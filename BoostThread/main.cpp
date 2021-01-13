#include <iostream>
#include <boost/thread.hpp>
#include <boost/chrono.hpp>

void dummy(int n,int number){
	Sleep(2000);
	std::cout << "thread"<<number<<" PID:" << GetCurrentThreadId()<<"¿ªÊ¼"<< std::endl;
	for (int i = 0; i < n; i++)
		Sleep(200);
	std::cout << n << std::endl;
	std::cout << "thread"<<number<<" PID:" << GetCurrentThreadId()<<"½áÊø" << std::endl;
}
int main(){
	boost::thread t1(dummy, 100,1);
	Sleep(500);
	boost::thread t2(dummy, 100,2);
	Sleep(500);
	boost::thread t3(dummy, 100,3);
	Sleep(500);
	t3.detach();
	//boost::this_thread::sleep_for(boost::chrono::milliseconds(200));

	t1.try_join_for(boost::chrono::milliseconds(200));
	t2.join();
	system("pause");
	return 0;
}