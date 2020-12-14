#include <iostream>

class WashClothe
{
public:
	WashClothe() {}
	virtual ~WashClothe() {}
	// 投入衣服
	virtual void Step1() = 0;
	// 加入洗涤剂
	virtual void Step2() = 0;
	// 设置模式
	virtual void Step3() = 0;
	// 脱水
	virtual void Step4() = 0;
	// 晾晒
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
		std::cout << "SuperWash Step1 投入大件衣服，准备进行超强洗" << std::endl;
	}
	virtual void Step2() {
		std::cout << "SuperWash Step2 加入三勺洗衣粉，再加快肥皂。" << std::endl;
	}
	virtual void Step3() {
		std::cout << "SuperWash Step3 设置超强洗模式，然后浸泡10分钟。" << std::endl;
	}
	virtual void Step4() {
		std::cout << "SuperWash Step4 漂洗并脱水。" << std::endl;
	}
	virtual void Step5() {
		std::cout << "SuperWash Step5 晾晒！" << std::endl;
	}
};

class WashGently :public WashClothe
{
public:
	virtual void Step1() {
		std::cout << "WashGently Step1 投入羊毛类或纯棉衣服" << std::endl;
	}							 
	virtual void Step2() {		 
		std::cout << "WashGently Step2 倒入洗衣液" << std::endl;
	}							 
	virtual void Step3() {		 
		std::cout << "WashGently Step3 设置轻柔洗模式" << std::endl;
	}							 
	virtual void Step4() {		 
		std::cout << "WashGently Step4 漂洗，并脱水" << std::endl;
	}							 
	virtual void Step5() {		 
		std::cout << "WashGently Step5 晾晒，不要暴晒" << std::endl;
	}
};

class Disinfection :public WashClothe
{
public:
	virtual void Step1() {
		std::cout << "Disinfection Step1 倒入消毒液" << std::endl;
	}
	virtual void Step2() {
		std::cout << "Disinfection Step2 选择消毒模式" << std::endl;
	}
	virtual void Step3() {
		std::cout << "Disinfection Step3 加水浸泡" << std::endl;
	}
	virtual void Step4() {
		std::cout << "Disinfection Step4 加热" << std::endl;
	}
	virtual void Step5() {
		std::cout << "Disinfection Step5 冲洗" << std::endl;
	}
};

class SuperFastWash :public WashClothe
{
public:
	virtual void Step1() {
		std::cout << "SuperFastWash Step1 投入衣服" << std::endl;
	}
	virtual void Step2() {
		std::cout << "SuperFastWash Step2 加入洗衣粉" << std::endl;
	}
	virtual void Step3() {
		std::cout << "SuperFastWash Step3 选择快洗模式" << std::endl;
	}
	virtual void Step4() {
		std::cout << "SuperFastWash Step4 漂洗，脱水" << std::endl;
	}
	virtual void Step5() {
		std::cout << "SuperFastWash Step5 晾晒" << std::endl;
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