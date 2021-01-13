#include <iostream>
#include <boost/asio.hpp>

using namespace std;
using namespace boost::asio;

int main(){

	// ����ʹ��asio�ĳ�������Ҫ��һ��I/Oִ��������
	// ������io_context,thread_pool����
	// I/Oִ���������ṩ��I/O���ܵķ��ʡ�
	boost::asio::io_context io;

	// ��������5s���ڡ�
	boost::asio::steady_timer t(io, boost::asio::chrono::seconds(5));
	cout << "Hello, Boost!" << endl;

	// wait() not return until the timer has expired,5 seconds after it was created.
	t.wait();
	cout << "Hello, world!" << endl;

	system("pause");
	return 0;
}