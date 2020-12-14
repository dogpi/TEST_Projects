#include <iostream>

using namespace std;

// 抽象类
class Shoes {
public:
	virtual ~Shoes() {}
	virtual void Show() = 0;
};
class Clothe
{
public:
	virtual void Show() = 0;
	virtual ~Clothe() {}
};

// 具体类
class NiKeShoes :public Shoes
{
public:
	void Show() {
		std::cout << "NiKe Shoes" << std::endl;
	}
};
class NiKeClothe :public Clothe
{
public:
	void Show() {
		std::cout << "NiKe Clothe" << std::endl;
	}
};

class AdidasShoes :public Shoes
{
public:
	void Show()
	{
		std::cout << "Adidas Shoes" << std::endl;
	}
};
class AdidasClothe :public Clothe
{
public:
	void Show()
	{
		std::cout << "Adidas Clothe" << std::endl;
	}
};

class LiNingShoes :public Shoes
{
public:
	void Show()
	{
		std::cout << "LiNing Shoes" << std::endl;
	}
};
class LiNingClothe :public Clothe
{
public:
	void Show()
	{
		std::cout << "LiNing Clothe" << std::endl;
	}
};

// 有N个类对象，分别继承两个抽象基类。
// 我们可以把这些类分为两类基类A和基类B。
// 使用多态可以用A和B可以表示这N个类

// 如果要有一个类对象，它拥有一个方法，可以返回不同的类的实例。如何实现它？
// 首先，如果这个类可以创建不同的类对象，那么可以通过模板类的方式实现它。
// 直接创建一个模板类，模板参数为要创建的类的类型即可。

// 那么，如果我们不是想返回具体的类对象的指针，而是返回这个类的抽象类的指针（基类、多态），如何实现它呢？
// 同理，模板参数传入基类和子类类型
// 模板类里通过创建函数创建子类，返回类型为基类类型即可。

// 根据以上表述，即可理解抽象模板工厂类


// 抽象模板工厂类
// 在该示例中可不创建抽象工厂类
template <class AbstructProduct_t>
class AbstractFactory
{
public:
	virtual AbstructProduct_t *CreateProduct() = 0;
	virtual ~AbstractFactory(){}
};
// 具体模板工厂类
template <class AbstructProduct_t,class ConcreteProduct_t>
class ConcreteFactory :public AbstractFactory<AbstructProduct_t>
{
public:
	AbstructProduct_t *CreateProduct() {
		return new ConcreteProduct_t();
	}
};


int main()
{
	ConcreteFactory<Shoes, NiKeShoes> nikeFactory;

	Shoes* pNikeShoes = nikeFactory.CreateProduct();
	pNikeShoes->Show();

	ConcreteFactory<Clothe, LiNingClothe> liningFactory;
	Clothe* pLiNingClothe = liningFactory.CreateProduct();
	pLiNingClothe->Show();


	delete pNikeShoes;
	delete pLiNingClothe;
	pNikeShoes = nullptr;
	pLiNingClothe = nullptr;

	system("pause");
	return 0;
}