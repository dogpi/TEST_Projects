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

// default constructor ��classû�ж����κ�constructor���ɱ��������ɵ����Լ���Ҫ��constructor��
int main()
{
	//Foo fo;	// VS --->ERROR δ��ʼ���ľֲ����� �޷����� fo ��Ϊû�е��ñ������Զ����ɵ�constructor������new Foo()�Żᡣg++ --->����g++����������ͨ��������val��ֵΪ0
	Foo* fo = new Foo();
	std::cout << fo->val << std::endl;		// VS ---> 0             g++ ---> 0

	Foo1 fo1;
	std::cout << fo1.val << std::endl;		// VS ---> -858993460    g++ ---> 0	

	//Bar ba;
	//std::cout << ba.fo.val << " " << ba.val << std::endl;	// VS ---> ERROR baδ��ʼ������ΪBarû��ָ�����캯����Ҳû��ʹ��newʹ��Ĭ�Ϲ��캯��       
	//														// g++ ---> 0  3569088		�����ԣ�g++�������У�Bar�����Foo��default���캯�������������Լ��Ĺ��캯����ba.val�Ͳ��ᱻ��ʼ����
	//														// Foo��default���캯�������ã�ba.fo.val�ᱻ��ʼ��Ϊ0
	Bar *ba1 = new Bar();
	std::cout << ba1->fo.val << " " << ba1->val << std::endl;	// VS ---> 0  0  g++ ---> 0  0   �����VS�ڷǳ�Ա����ĵط�����Foo fo�ͱ�������Ͳ�������28�оͱ���

	Bar1 *ba2 = new Bar1();
	std::cout << ba2->fo.val << " " << ba2->fo0.val << " " << ba2->val << std::endl; // VS ---> 0 0 0   g++ --->  0 0 0
	system("pause");
	return 0;
}