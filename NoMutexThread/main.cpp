#include <iostream>
#include <boost/thread.hpp>
#include <boost/atomic.hpp>

long counter = 0;
boost::mutex mtx;

boost::atomic<long> a_counter(0);

void func(void){
	for (long i = 0; i < 1000000; ++i){
		++counter;
	}
}

void func_mutex(void){
	mtx.lock();
	for (long i = 0; i < 1000000; ++i){
		++counter;
	}
	mtx.unlock();
}

void func_atomic(void){
	for (long i = 0; i < 1000000; ++i){
		++a_counter;
	}
}

int main()
{
	
	//boost::thread t1(func);
	//boost::thread t2(func);

	//boost::thread t1(func_mutex);
	//boost::thread t2(func_mutex);

	boost::thread t1(func_atomic);
	boost::thread t2(func_atomic);

	t1.join();
	t2.join();
	std::cout << counter << std::endl;
	std::cout << a_counter << std::endl;

	system("pause");
	return 0;
}