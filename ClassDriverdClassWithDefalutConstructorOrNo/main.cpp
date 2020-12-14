#include <iostream>

class WithDeaultConstructor
{
public:
	int val;
};

class Driverd:public WithDeaultConstructor
{
public:
	int value;
};

class NoDeaultConstructor
{
public:
	NoDeaultConstructor() {
		val = 1;
	}
	int val;
};

class Driverd1 :public NoDeaultConstructor
{
public:
	int value;
};

int main()
{
	// Driverd d0;
	// std::cout << d0.val << " " << d0.value << std::endl;	// VS ---> ERROR   g++ ---> 7960096 0 g++中基类的子类对象会被初始化

	Driverd *d = new Driverd();
	std::cout << d->val << " " << d->value << std::endl;  // VS ---> 0 0  g++ ---> 0  0

	Driverd1 d2;
	std::cout << d2.val << " " << d2.value << std::endl; // VS ---> 1 -858993460  g++ ---> 1 0

	system("pause");
	return 0;
}

// 看看这些初始化，在不同的编译器环境下初始化的方式也不一样，为了避免这些幺蛾子，强烈推荐创建无参构造函数来初始化类的成员变量。