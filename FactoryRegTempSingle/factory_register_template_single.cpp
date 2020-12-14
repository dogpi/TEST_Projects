#include <iostream>
#include <map>
#include <string>
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

template <class ProductType_t>
class IProductRegistrar
{
public:
	virtual ProductType_t *CreateProduct() = 0;
protected:
	IProductRegistrar() {}
	virtual ~IProductRegistrar() {}
private:
	IProductRegistrar(const IProductRegistrar &);
	const IProductRegistrar &operator=(const IProductRegistrar &);
};

template <class ProductType_t>
class ProductFactory
{
public:
	// ��ȡ����������������ʵ����Ψһ��
	static ProductFactory<ProductType_t> &Instance()
	{
		static ProductFactory<ProductType_t> instance;
		return instance;
	}

	// ��Ʒע��
	void RegisterProduct(IProductRegistrar<ProductType_t> *registrar, std::string name)
	{
		m_ProductRegistry[name] = registrar;
	}

	// ��������name����ȡ��Ӧ����Ĳ�Ʒ����
	ProductType_t *GetProduct(std::string name)
	{
		// ��map�ҵ��Ѿ�ע����Ĳ�Ʒ�������ز�Ʒ����
		if (m_ProductRegistry.find(name) != m_ProductRegistry.end())
		{
			return m_ProductRegistry[name]->CreateProduct();
		}

		// δע��Ĳ�Ʒ���򱨴�δ�ҵ�
		std::cout<< "No product found for " << name << std::endl;

		return NULL;
	}
private:
	// ��ֹ�ⲿ������鹹
	ProductFactory() {}
	~ProductFactory() {}

	// ��ֹ�ⲿ�����͸�ֵ����
	ProductFactory(const ProductFactory &);
	const ProductFactory &operator=(const ProductFactory &);

	// ����ע����Ĳ�Ʒ��key:��Ʒ���� , value:��Ʒ����
	std::map<std::string, IProductRegistrar<ProductType_t> *> m_ProductRegistry;
};

// ��Ʒע��ģ���࣬���ڴ��������Ʒ�ʹӹ�����ע���Ʒ
// ģ����� ProductType_t ��ʾ�����ǲ�Ʒ�����ࣨ���ࣩ��ProductImpl_t ��ʾ�����Ǿ����Ʒ����Ʒ��������ࣩ
template <class ProductType_t, class ProductImpl_t>
class ProductRegistrar : public IProductRegistrar<ProductType_t>
{
public:
	// ���캯��������ע���Ʒ��������ֻ����ʾ����
	explicit ProductRegistrar(std::string name)
	{
		// ͨ�����������Ѳ�Ʒע�ᵽ����
		ProductFactory<ProductType_t>::Instance().RegisterProduct(this, name);
	}

	// ���������Ʒ����ָ��
	ProductType_t *CreateProduct()
	{
		return new ProductImpl_t();
	}
};

int main()
{
	// ע���Ʒ����ΪShoes�����ࣩ����ƷΪNiKe�����ࣩ����������Ʒ��Ϊnike
	ProductRegistrar<Shoes, NiKeShoes> nikeShoes("nike");

	Shoes* pNiKeShoes = ProductFactory<Shoes>::Instance().GetProduct("nike");
	pNiKeShoes->Show();

	ProductRegistrar<Clothe,AdidasClothe > adidasClothe("adidas");
	Clothe* pAdidasClothe = ProductFactory<Clothe>::Instance().GetProduct("adidas");
	pAdidasClothe->Show();

	delete pNiKeShoes;
	pNiKeShoes = nullptr;
	delete pAdidasClothe;
	pAdidasClothe = nullptr;

	system("pause");
	return 0;
}