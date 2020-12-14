#include <iostream>

using namespace std;

// 抽象类
class Shoes {
public:
	virtual ~Shoes() {}
	virtual void Show() = 0;
};

// 具体类
class NiKeShoes :public Shoes
{
public:
	void Show() {
		std::cout << "NiKe" << std::endl;
	}
};

class AdidasShoes :public Shoes
{
public:
	void Show()
	{
		std::cout << "Adidas" << std::endl;
	}
};

class LiNingShoes :public Shoes
{
public:
	void Show()
	{
		std::cout << "LiNing" << std::endl;
	}
};



// 工厂类
class ShoesFactory {
public:
	virtual Shoes* CreateShoes() = 0;
	virtual ~ShoesFactory() {}
};

class NiKeProducer :public ShoesFactory
{
public:
	Shoes * CreateShoes() {
		return new NiKeShoes;
	}
};

class AdidasProducer :public ShoesFactory
{
public:
	Shoes * CreateShoes() {
		return new AdidasShoes;
	}
};

class LiNingProducer :public ShoesFactory
{
public:
	Shoes * CreateShoes() {
		return new LiNingShoes;
	}
};

int main()
{
	ShoesFactory * niKeProducer = new NiKeProducer();

	Shoes *pNikeShoes = niKeProducer->CreateShoes();
	if (NULL != pNikeShoes) {
		pNikeShoes->Show();
		delete pNikeShoes;
		pNikeShoes = NULL;
	}
	ShoesFactory * adidasProducer = new AdidasProducer();
	Shoes *pLiningShoes = adidasProducer->CreateShoes();
	if (NULL != pLiningShoes) {
		pLiningShoes->Show();
		delete pLiningShoes;
		pLiningShoes = NULL;
	}

	ShoesFactory * liNingProducer = new LiNingProducer();
	Shoes *pAdidasShoes = liNingProducer->CreateShoes();
	if (NULL != pAdidasShoes) {
		pAdidasShoes->Show();
		delete pAdidasShoes;
		pAdidasShoes = NULL;
	}

	system("pause");
	return 0;
}