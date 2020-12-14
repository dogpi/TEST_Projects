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


// 工厂类
class Factory {
public:
	virtual Shoes* CreateShoes() = 0;
	virtual Clothe* CreateClothe() = 0;
	virtual ~Factory() {}
};

class NiKeProducer :public Factory
{
public:
	Shoes * CreateShoes() {
		return new NiKeShoes;
	}
	Clothe * CreateClothe() {
		return new NiKeClothe();
	}
};

class AdidasProducer :public Factory
{
public:
	Shoes * CreateShoes() {
		return new AdidasShoes;
	}
	Clothe * CreateClothe() {
		return new AdidasClothe();
	}
};

class LiNingProducer :public Factory
{
public:
	Shoes * CreateShoes() {
		return new LiNingShoes;
	}
	Clothe * CreateClothe() {
		return new LiNingClothe();
	}
};

int main()
{
	Factory * niKeProducer = new NiKeProducer();
	Shoes *pNikeShoes = niKeProducer->CreateShoes();
	if (NULL != pNikeShoes) {
		pNikeShoes->Show();
		delete pNikeShoes;
		pNikeShoes = NULL;
	}
	Clothe *pNikeClothe = niKeProducer->CreateClothe();
	if (NULL != pNikeClothe) {
		pNikeClothe->Show();
		delete pNikeClothe;
		pNikeClothe = NULL;
	}

	Factory * adidasProducer = new AdidasProducer();
	Shoes *pLiningShoes = adidasProducer->CreateShoes();
	if (NULL != pLiningShoes) {
		pLiningShoes->Show();
		delete pLiningShoes;
		pLiningShoes = NULL;
	}
	Clothe *pLiningClothe = adidasProducer->CreateClothe();
	if (NULL != pLiningClothe) {
		pLiningClothe->Show();
		delete pLiningClothe;
		pLiningClothe = NULL;
	}

	Factory * liNingProducer = new LiNingProducer();
	Shoes *pAdidasShoes = liNingProducer->CreateShoes();
	if (NULL != pAdidasShoes) {
		pAdidasShoes->Show();
		delete pAdidasShoes;
		pAdidasShoes = NULL;
	}
	Clothe *pAdidasClothe = liNingProducer->CreateClothe();
	if (NULL != pAdidasClothe) {
		pAdidasClothe->Show();
		delete pAdidasClothe;
		pAdidasClothe = NULL;
	}


	system("pause");
	return 0;
}