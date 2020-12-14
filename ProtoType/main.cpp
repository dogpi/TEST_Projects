#include <iostream>
#include <string>

/*
	������ࣺ

	1��  Prototype:������࣬����ԭ�͵Ļ��࣬�ṩClone�ӿں���

	�ӿں�����

	1��  Prototype::Clone���������麯�������ݲ�ͬ����������ʵ������������

	������
	Prototypeģʽ��ʵ���ǳ�˵�ġ����⹹�캯������һ��ʵ�֣�C++��ʵ�ֻ����в�û��֧��������ԣ�
	����ͨ����ͬ������ʵ�ֵ�Clone�ӿں�����������롰���⹹�캯����ͬ����Ч����
	��һ���������������ģʽ�����ã�������һ�ҵ�������Կ�׵ģ��������ṩ��Կ�׵ķ����ṩClone�ӿں�������
	����Ҫ��ʲôԿ������֪��ֻ���ṩ���ַ��񣬾�����Ҫ��ʲôԿ��ֻ�е�����������Կ�׵�ԭ�Ͳ�����á�
	Ҳ����˵����Ҫһ���ṩ�������Ķ���ͬʱ����Ҫһ��ԭ�ͣ�Prototype������Ȼ��֪������ʲôҪ��Կ�ס�
*/

class Prototype
{
public:
	Prototype() {}
	virtual ~Prototype() {}
	virtual Prototype* Clone() = 0;
};

class A :public Prototype
{
public:
	A() {}
	A(const A &a){
		this->ObjName = a.ObjName;
		this->Author = a.Author;
	}
	~A() {}
	std::string ObjName = "dogpi";
	std::string Author = "dogpi--";
	
	virtual Prototype* Clone();
};

Prototype* A::Clone() {
	return new A(*this);
}

int main()
{

	Prototype *p = new A();
	std::cout << "name: " << ((A*)p)->ObjName << std::endl;
	Prototype *p2 = p->Clone();
	((A*)p)->ObjName = "catpi";
	std::cout << "name: " << ((A*)p)->ObjName << std::endl;
	std::cout << "name: " << ((A*)p2)->ObjName << std::endl;

	system("pause");
	return 0;
}