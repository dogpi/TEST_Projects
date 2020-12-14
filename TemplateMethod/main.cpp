#include <iostream>

class WashClothe
{
public:
	WashClothe() {}
	virtual ~WashClothe() {}
	// Ͷ���·�
	virtual void Step1() = 0;
	// ����ϴ�Ӽ�
	virtual void Step2() = 0;
	// ����ģʽ
	virtual void Step3() = 0;
	// ��ˮ
	virtual void Step4() = 0;
	// ��ɹ
	virtual void Step5() = 0;
	void Start() {
		this->Step1();
		this->Step2();
		this->Step3();
		this->Step4();
		this->Step5();
	}
};

class SuperWash :public WashClothe
{
public:
	virtual void Step1() {
		std::cout << "SuperWash Step1 Ͷ�����·���׼�����г�ǿϴ" << std::endl;
	}
	virtual void Step2() {
		std::cout << "SuperWash Step2 ��������ϴ�·ۣ��ټӿ����" << std::endl;
	}
	virtual void Step3() {
		std::cout << "SuperWash Step3 ���ó�ǿϴģʽ��Ȼ�����10���ӡ�" << std::endl;
	}
	virtual void Step4() {
		std::cout << "SuperWash Step4 Ưϴ����ˮ��" << std::endl;
	}
	virtual void Step5() {
		std::cout << "SuperWash Step5 ��ɹ��" << std::endl;
	}
};

class WashGently :public WashClothe
{
public:
	virtual void Step1() {
		std::cout << "WashGently Step1 Ͷ����ë������·�" << std::endl;
	}							 
	virtual void Step2() {		 
		std::cout << "WashGently Step2 ����ϴ��Һ" << std::endl;
	}							 
	virtual void Step3() {		 
		std::cout << "WashGently Step3 ��������ϴģʽ" << std::endl;
	}							 
	virtual void Step4() {		 
		std::cout << "WashGently Step4 Ưϴ������ˮ" << std::endl;
	}							 
	virtual void Step5() {		 
		std::cout << "WashGently Step5 ��ɹ����Ҫ��ɹ" << std::endl;
	}
};

class Disinfection :public WashClothe
{
public:
	virtual void Step1() {
		std::cout << "Disinfection Step1 ��������Һ" << std::endl;
	}
	virtual void Step2() {
		std::cout << "Disinfection Step2 ѡ������ģʽ" << std::endl;
	}
	virtual void Step3() {
		std::cout << "Disinfection Step3 ��ˮ����" << std::endl;
	}
	virtual void Step4() {
		std::cout << "Disinfection Step4 ����" << std::endl;
	}
	virtual void Step5() {
		std::cout << "Disinfection Step5 ��ϴ" << std::endl;
	}
};

class SuperFastWash :public WashClothe
{
public:
	virtual void Step1() {
		std::cout << "SuperFastWash Step1 Ͷ���·�" << std::endl;
	}
	virtual void Step2() {
		std::cout << "SuperFastWash Step2 ����ϴ�·�" << std::endl;
	}
	virtual void Step3() {
		std::cout << "SuperFastWash Step3 ѡ���ϴģʽ" << std::endl;
	}
	virtual void Step4() {
		std::cout << "SuperFastWash Step4 Ưϴ����ˮ" << std::endl;
	}
	virtual void Step5() {
		std::cout << "SuperFastWash Step5 ��ɹ" << std::endl;
	}
};


int main()
{

	WashClothe *wc1 = new SuperFastWash();
	wc1->Start();
	std::cout << "*************************************" << std::endl;

	WashClothe *wc2 = new SuperFastWash();
	wc2->Start();
	std::cout << "*************************************" << std::endl;
	
	WashClothe *wc3 = new Disinfection();
	wc3->Start();
	std::cout << "*************************************" << std::endl;

	system("pause");
	return 0;
}