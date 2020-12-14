#include <iostream>

using namespace std;

// ������
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

// ������
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

// ��N������󣬷ֱ�̳�����������ࡣ
// ���ǿ��԰���Щ���Ϊ�������A�ͻ���B��
// ʹ�ö�̬������A��B���Ա�ʾ��N����

// ���Ҫ��һ���������ӵ��һ�����������Է��ز�ͬ�����ʵ�������ʵ������
// ���ȣ�����������Դ�����ͬ���������ô����ͨ��ģ����ķ�ʽʵ������
// ֱ�Ӵ���һ��ģ���࣬ģ�����ΪҪ������������ͼ��ɡ�

// ��ô��������ǲ����뷵�ؾ����������ָ�룬���Ƿ��������ĳ������ָ�루���ࡢ��̬�������ʵ�����أ�
// ͬ��ģ���������������������
// ģ������ͨ�����������������࣬��������Ϊ�������ͼ��ɡ�

// �������ϱ���������������ģ�幤����


// ����ģ�幤����
// �ڸ�ʾ���пɲ��������󹤳���
template <class AbstructProduct_t>
class AbstractFactory
{
public:
	virtual AbstructProduct_t *CreateProduct() = 0;
	virtual ~AbstractFactory(){}
};
// ����ģ�幤����
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