#include <iostream>
#include <boost/asio.hpp>

using namespace std;
using namespace boost::asio;

int main(){

	// 所有使用asio的程序都至少要有一个I/O执行上下文
	// 可以是io_context,thread_pool对象。
	// I/O执行上下文提供对I/O功能的访问。
	boost::asio::io_context io;

	// 从现在起5s后到期。
	boost::asio::steady_timer t(io, boost::asio::chrono::seconds(5));
	cout << "Hello, Boost!" << endl;

	// wait() not return until the timer has expired,5 seconds after it was created.
	t.wait();
	cout << "Hello, world!" << endl;

	system("pause");
	return 0;
}