#include <iostream>
#include <boost/asio.hpp>
#include <boost/thread/thread.hpp>
#include <boost/bind/bind.hpp>

/*
	单线程方法的缺点，尤其是对于服务器：
		1、当处理函数调用过长时相应会很慢
		2、限制了使用多线程系统的性能

	解决方法：
		1、创建一个线程池，调用io_context::run()，使程序能够并发执行
		2、线程间数据同步
*/


// 该类将同时运行两个定时器
class printer
{
public:
	// 除了需要初始化一对boost::asio::steady_timer成员，还需要初始化一个strand_成员
	// strand_成员是boost::asio::strand<boost::asio::io_context::executor_type>类对象。
	// strand类模板是一个执行程序适配器，该适配器确保对于通过它调度的那些处理程序，要求正在执行的处理程序在下一个启动之前完成。
	// 无论调用io_context :: run（）的线程数量如何，都可以保证这一点。
	// 当然，这些处理程序可能正在被其他未通过strand分配器，或其他strand分配器的程序处同步调用。
	printer(boost::asio::io_context& io)
		: strand_(boost::asio::make_strand(io)),
		timer1_(io, boost::asio::chrono::seconds(1)),
		timer2_(io, boost::asio::chrono::seconds(1)),
		count_(0)
	{
		/*
			当初始化异步操作时，每个被调用的handler都要被绑定到一个boost::asio::strand<boost::asio::io_context::executor_type>对象。
			boost::asio::bind_executor()函数返回一个新的handler，这个新的handler将被strand自动分配到他包含的handler中。
			通过绑定handlers到相同的strand，我们可以确保这些hadnler不会同时执行。（不会产生资源竞争的现象）
		*/
		timer1_.async_wait(boost::asio::bind_executor(strand_,
			boost::bind(&printer::print1, this)));

		timer2_.async_wait(boost::asio::bind_executor(strand_,
			boost::bind(&printer::print2, this)));
	}

	~printer()
	{
		std::cout << "Final count is " << count_ << std::endl;
	}
	//在多线程程序中，用于异步操作的处理程序如果访问共享资源，则应该同步。
	//在本教程中，处理程序（print1和print2）
	//使用的共享资源为std::cout和count_数据成员。
	void print1()
	{
		if (count_ < 10)
		{
			std::cout << "Timer 1: " << count_ << std::endl;
			++count_;

			timer1_.expires_at(timer1_.expiry() + boost::asio::chrono::seconds(1));

			timer1_.async_wait(boost::asio::bind_executor(strand_,
				boost::bind(&printer::print1, this)));
		}
	}

	void print2()
	{
		if (count_ < 10)
		{
			std::cout << "Timer 2: " << count_ << std::endl;
			++count_;

			timer2_.expires_at(timer2_.expiry() + boost::asio::chrono::seconds(1));

			timer2_.async_wait(boost::asio::bind_executor(strand_,
				boost::bind(&printer::print2, this)));
		}
	}

private:
	boost::asio::strand<boost::asio::io_context::executor_type> strand_;
	boost::asio::steady_timer timer1_;
	boost::asio::steady_timer timer2_;
	int count_;
};

// io_context::run()被两个线程调用
// 一个是main函数，一个是子线程（通过使用boost::thread对象实现）。

int main()
{
	boost::asio::io_context io;
	printer p(io);
	boost::thread t(boost::bind(&boost::asio::io_context::run, &io));
	
	io.run();
	t.join();

	system("pause");
	return 0;
}