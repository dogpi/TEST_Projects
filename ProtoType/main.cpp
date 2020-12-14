#include <iostream>
#include <string>

/*
	抽象基类：

	1）  Prototype:虚拟基类，所有原型的基类，提供Clone接口函数

	接口函数：

	1）  Prototype::Clone函数：纯虚函数，根据不同的派生类来实例化创建对象。

	解析：
	Prototype模式其实就是常说的“虚拟构造函数”的一个实现，C++的实现机制中并没有支持这个特性，
	但是通过不同派生类实现的Clone接口函数可以完成与“虚拟构造函数”同样的效果。
	举一个例子来解释这个模式的作用，假设有一家店铺是配钥匙的，他对外提供配钥匙的服务（提供Clone接口函数），
	你需要配什么钥匙它不知道只是提供这种服务，具体需要配什么钥匙只有到了真正看到钥匙的原型才能配好。
	也就是说，需要一个提供这个服务的对象，同时还需要一个原型（Prototype），不然不知道该配什么要的钥匙。
*/

class Prototype
{
public:
	Prototype() {}
	virtual ~Prototype() {}
	virtual Prototype* Clone() = 0;
};

class A :public Prototype
{
public:
	A() {}
	A(const A &a){
		this->ObjName = a.ObjName;
		this->Author = a.Author;
	}
	~A() {}
	std::string ObjName = "dogpi";
	std::string Author = "dogpi--";
	
	virtual Prototype* Clone();
};

Prototype* A::Clone() {
	return new A(*this);
}

int main()
{

	Prototype *p = new A();
	std::cout << "name: " << ((A*)p)->ObjName << std::endl;
	Prototype *p2 = p->Clone();
	((A*)p)->ObjName = "catpi";
	std::cout << "name: " << ((A*)p)->ObjName << std::endl;
	std::cout << "name: " << ((A*)p2)->ObjName << std::endl;

	system("pause");
	return 0;
}