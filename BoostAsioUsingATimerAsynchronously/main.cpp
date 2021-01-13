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


	// �첽�ȴ����õȴ�������������ǰ���򣬵���ʱ���ں�ִ�д���ĺ�����
	t.async_wait(&print);
	cout << "io.run()" << endl;


	// ����������io_context::run()��asio�����ȷ�����ӵ�ǰ���ڵ���io_context::run()���߳��е��ûص��������
	// ��ˣ����ǵ���io_context::run()������������Զ��������첽�ȴ���ɵĻص���
	// Ҳ����˵io.run()������ȴ��첽���򷵻ء�
	// �൱���̵߳�join()��
	// ����������첽����t.async_wait(...)��io.run()�����������ء�
	io.run();
	cout << "after io.run()" << endl;
	system("pause");
	return 0;
}