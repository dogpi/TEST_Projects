#include <iostream>
#include <boost/asio.hpp>
#include <boost/thread/thread.hpp>
#include <boost/bind/bind.hpp>

/*
	���̷߳�����ȱ�㣬�����Ƕ��ڷ�������
		1�������������ù���ʱ��Ӧ�����
		2��������ʹ�ö��߳�ϵͳ������

	���������
		1������һ���̳߳أ�����io_context::run()��ʹ�����ܹ�����ִ��
		2���̼߳�����ͬ��
*/


// ���ཫͬʱ����������ʱ��
class printer
{
public:
	// ������Ҫ��ʼ��һ��boost::asio::steady_timer��Ա������Ҫ��ʼ��һ��strand_��Ա
	// strand_��Ա��boost::asio::strand<boost::asio::io_context::executor_type>�����
	// strand��ģ����һ��ִ�г�������������������ȷ������ͨ�������ȵ���Щ�������Ҫ������ִ�еĴ����������һ������֮ǰ��ɡ�
	// ���۵���io_context :: run�������߳�������Σ������Ա�֤��һ�㡣
	// ��Ȼ����Щ�������������ڱ�����δͨ��strand��������������strand�������ĳ���ͬ�����á�
	printer(boost::asio::io_context& io)
		: strand_(boost::asio::make_strand(io)),
		timer1_(io, boost::asio::chrono::seconds(1)),
		timer2_(io, boost::asio::chrono::seconds(1)),
		count_(0)
	{
		/*
			����ʼ���첽����ʱ��ÿ�������õ�handler��Ҫ���󶨵�һ��boost::asio::strand<boost::asio::io_context::executor_type>����
			boost::asio::bind_executor()��������һ���µ�handler������µ�handler����strand�Զ����䵽��������handler�С�
			ͨ����handlers����ͬ��strand�����ǿ���ȷ����Щhadnler����ͬʱִ�С������������Դ����������
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
	//�ڶ��̳߳����У������첽�����Ĵ������������ʹ�����Դ����Ӧ��ͬ����
	//�ڱ��̳��У��������print1��print2��
	//ʹ�õĹ�����ԴΪstd::cout��count_���ݳ�Ա��
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

// io_context::run()�������̵߳���
// һ����main������һ�������̣߳�ͨ��ʹ��boost::thread����ʵ�֣���

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