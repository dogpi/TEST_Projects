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
		std::cout << "I can Fly with 脚脚" << std::endl;
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
		std::cout << "I can Fly with 翅膀" << std::endl;
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
		std::cout << "I can Fly with 乌漆嘛黑" << std::endl;
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
	// 现在用户想提取出两个技能，交给自己的人工合成鸟
	// fly with 脚脚 + jiu jiu
	// 学习脚脚起飞技能
	Bird* jiaojaio = new Chicken();
	contex.Fly(jiaojaio);
	// 学习jiu jiu 叫技能
	Bird* jiujiu = new Sparrow();
	contex.Voice(jiujiu);
	system("pause");
	return 0;
}