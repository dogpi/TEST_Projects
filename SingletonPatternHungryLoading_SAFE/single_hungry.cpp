#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

// 所谓懒汉式就是在类初始化时不会自动创建对象

class SingleHungry
{
public:
	static SingleHungry *GetInstance();
	static void deleteInstance();

	void PrintAddr();
private:
	SingleHungry();
	~SingleHungry();
	// 拷贝构造函数和赋值构造函数私有化，禁止拷贝和赋值
	SingleHungry(const SingleHungry& sig) {}
	const SingleHungry &operator=(const SingleHungry&sig) {}
	static SingleHungry* m_instance;
};
SingleHungry* SingleHungry::m_instance = new SingleHungry();

SingleHungry * SingleHungry::GetInstance() {

	return m_instance;
}

void SingleHungry::deleteInstance()
{

}

void SingleHungry::PrintAddr()
{
	std::cout << "instance addr:" << this << std::endl;
}

SingleHungry::SingleHungry() {
	std::cout << "construct" << std::endl;
}

SingleHungry::~SingleHungry() {
	std::cout << "destruct" << std::endl;
	deleteInstance();
}

void call_back(int x)
{
	std::cout << "thread:" << x << std::endl;
	SingleHungry*  instance = SingleHungry::GetInstance();
	instance->PrintAddr();
}

int main()
{

	thread t1(call_back, 1);
	thread t2(call_back, 2);
	thread t3(call_back, 3);
	thread t4(call_back, 4);
	thread t5(call_back, 5);

	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();
	system("pause");
	return 0;
}