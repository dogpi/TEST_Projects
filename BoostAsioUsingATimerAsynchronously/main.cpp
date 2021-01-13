#include <iostream>
#include <boost/asio.hpp>

using namespace std;
using namespace boost::asio;

void print(const boost::system::error_code&)
{
	std::cout << "Hello, world!" << std::endl;
}
int main(){

	boost::asio::io_context io;
	boost::asio::steady_timer t(io, boost::asio::chrono::seconds(5));


	// 异步等待，该等待并不会阻塞当前程序，当定时到期后，执行传入的函数。
	t.async_wait(&print);
	cout << "io.run()" << endl;


	// 这里必须调用io_context::run()，asio库可以确保仅从当前正在调用io_context::run()的线程中调用回调处理程序。
	// 因此，除非调用io_context::run()函数，否则将永远不会调用异步等待完成的回调。
	// 也就是说io.run()在这里等待异步程序返回。
	// 相当与线程的join()。
	// 如果不调用异步调用t.async_wait(...)，io.run()将会立即返回。
	io.run();
	cout << "after io.run()" << endl;
	system("pause");
	return 0;
}