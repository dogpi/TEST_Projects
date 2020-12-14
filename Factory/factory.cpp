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

enum SHOES_TYPE {
	NIKE,
	LINING,
	ADIDAS
};

// 工厂类
class ShoesFactory {
public:
	Shoes* CreateShoes(SHOES_TYPE type) {
		switch (type)
		{
		case NIKE:
			return new NiKeShoes();
			break;
		case LINING:
			return new LiNingShoes();
			break;
		case ADIDAS:
			return new AdidasShoes();
			break;
		default:
			break;
		}
	}
};

int main()
{
	// 构造工厂对象
	ShoesFactory shoesFactory;

	Shoes *pNikeShoes = shoesFactory.CreateShoes(NIKE);
	if (NULL != pNikeShoes) {
		pNikeShoes->Show();
		delete pNikeShoes;
		pNikeShoes = NULL;
	}

	Shoes *pLiningShoes = shoesFactory.CreateShoes(LINING);
	if (NULL != pLiningShoes) {
		pLiningShoes->Show();
		delete pLiningShoes;
		pLiningShoes = NULL;
	}

	Shoes *pAdidasShoes = shoesFactory.CreateShoes(ADIDAS);
	if (NULL != pAdidasShoes) {
		pAdidasShoes->Show();
		delete pAdidasShoes;
		pAdidasShoes = NULL;
	}

	system("pause");
	return 0;
}