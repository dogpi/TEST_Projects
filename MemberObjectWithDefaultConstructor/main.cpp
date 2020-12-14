#include <iostream>

class Foo 
{ 
public:
	int val;
};

class Foo0
{
public:
	int val;
};

class Foo1
{
public:
	Foo1() {} 
	Foo1(int) {}
	int val;
};

class Bar
{
public:
	Foo fo;
	int val;
};

class Bar1
{
public:
	Foo fo;
	Foo0 fo0;
	int val;
};

// default constructor 是class没有定义任何constructor，由编译器生成的它自己需要的constructor。
int main()
{
	//Foo fo;	// VS --->ERROR 未初始化的局部变量 无法生成 fo 因为没有调用编译器自动生成的constructor，调用new Foo()才会。g++ --->但是g++编译器可以通过，并给val赋值为0
	Foo* fo = new Foo();
	std::cout << fo->val << std::endl;		// VS ---> 0             g++ ---> 0

	Foo1 fo1;
	std::cout << fo1.val << std::endl;		// VS ---> -858993460    g++ ---> 0	

	//Bar ba;
	//std::cout << ba.fo.val << " " << ba.val << std::endl;	// VS ---> ERROR ba未初始化，因为Bar没有指定构造函数，也没有使用new使用默认构造函数       
	//														// g++ ---> 0  3569088		很明显，g++编译器中，Bar会调用Foo的default构造函数，不会生成自己的构造函数，ba.val就不会被初始化。
	//														// Foo的default构造函数被调用，ba.fo.val会被初始化为0
	Bar *ba1 = new Bar();
	std::cout << ba1->fo.val << " " << ba1->val << std::endl;	// VS ---> 0  0  g++ ---> 0  0   很奇怪VS在非成员对象的地方调用Foo fo就报错，这里就不报错。（28行就报错）

	Bar1 *ba2 = new Bar1();
	std::cout << ba2->fo.val << " " << ba2->fo0.val << " " << ba2->val << std::endl; // VS ---> 0 0 0   g++ --->  0 0 0
	system("pause");
	return 0;
}