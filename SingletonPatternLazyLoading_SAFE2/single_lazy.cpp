#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

// ��ν����ʽ���������ʼ��ʱ�����Զ���������

class SingleLazy
{
public:
	static SingleLazy &GetInstance();
	static void deleteInstance();

	void PrintAddr();
private:
	SingleLazy();
	~SingleLazy();
	// �������캯���͸�ֵ���캯��˽�л�����ֹ�����͸�ֵ
	SingleLazy(const SingleLazy& sig) {}
	const SingleLazy &operator=(const SingleLazy&sig) {}

};


SingleLazy & SingleLazy::GetInstance() {
	static SingleLazy instance;
	return instance;
}

void SingleLazy::deleteInstance()
{
	
}

void SingleLazy::PrintAddr()
{
	std::cout << "instance addr:" << this << std::endl;
}

SingleLazy::SingleLazy() {
	std::cout << "construct" << std::endl;
}

SingleLazy::~SingleLazy() {
	std::cout << "destruct" << std::endl;
	deleteInstance();
}

void call_back(int x)
{
	std::cout << "thread:" << x << std::endl;
	SingleLazy*  instance = &SingleLazy::GetInstance();
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