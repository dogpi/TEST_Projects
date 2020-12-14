#include <iostream>

class Bird
{
public:
	Bird() {};
	virtual ~Bird() {};
	virtual void Fly() {
		std::cout << "I can Fly" << std::endl;
	}
	virtual void Voice() {
		std::cout << "ji ji" << std::endl;
	}
};

class Chicken :public Bird
{
public:
	Chicken() {}
	~Chicken(){}
	void Fly() {
		std::cout << "I can Fly with �Ž�" << std::endl;
	}
	void Voice() {
		std::cout << "ge ge" << std::endl;
	}
};

class Sparrow:public Bird
{
public:
	Sparrow(){}
	~Sparrow(){}
	void Fly() {
		std::cout << "I can Fly with ���" << std::endl;
	}
	void Voice() {
		std::cout << "jiu jiu" << std::endl;
	}
};

class Crow :public Bird
{
public:
	Crow() {}
	~Crow(){}

	void Fly() {
		std::cout << "I can Fly with �������" << std::endl;
	}
	void Voice() {
		std::cout << "ga ga" << std::endl;
	}
};

class Context {
public:
	Context(){}
	~Context(){}
	void Fly(Bird *b) {
		b->Fly();
	}
	void Voice(Bird *b) {
		b->Voice();
	}
};



int main()
{
	Context contex;
	// �����û�����ȡ���������ܣ������Լ����˹��ϳ���
	// fly with �Ž� + jiu jiu
	// ѧϰ�Ž���ɼ���
	Bird* jiaojaio = new Chicken();
	contex.Fly(jiaojaio);
	// ѧϰjiu jiu �м���
	Bird* jiujiu = new Sparrow();
	contex.Voice(jiujiu);
	system("pause");
	return 0;
}