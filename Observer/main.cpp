#include <iostream>
#include <vector>
/*
观察者模式：
	被观察者有动作做出，观察者也会做出对应的反应。
	也可以理解为发布者和订阅者。发布者发布消息给订阅者，订阅者根据消息进行处理。

*/

class Upper;

class Observer
{
public:
	Observer() {}
	virtual ~Observer() {}
	virtual void View() = 0;


};

class Upper 
{
public:
	std::vector<Observer*> fans;
	std::string status;
	// 通知观察者
	void Notify()
	{
		for (auto ele : fans) {
			ele->View();
		}
	}

	void Update(std::string s) {
		SetStatus(s);
	}

	std::string GetStatus() {
		return status;
	}
private:
	void SetStatus(std::string s) {
		status = s;
		Notify();
	}
};

class Dogpi :public Upper
{
public:
	std::string name = "dogpi";
	int fans_count = 3;

};



class fan1 :public Observer
{
public:
	std::vector<Upper*> uppers;
	virtual void View() {
		std::cout << "下次一定" << std::endl;
	}
public:
	// 刷新，查看关注的up有没有更新
	void Refresh() {
		for (Upper* ele : uppers) {
			ele->GetStatus();
		}
	}
};

class fan2 :public Observer
{
public:
	std::vector<Upper*> uppers;
	virtual void View() {
		std::cout << "已三连， 加油" << std::endl;
	}
public:
	// 刷新，查看关注的up有没有更新
	void Refresh() {
		for (Upper* ele : uppers) {
			ele->GetStatus();
		}
	}
};

class fan3 :public Observer
{
public:
	std::vector<Upper*> uppers;
	virtual void View() {
		std::cout << "哇哦，又在这卖惨"<< std::endl;
	}
public:
	// 刷新，查看关注的up有没有更新
	void Refresh() {
		for (Upper* ele : uppers) {
			ele->GetStatus();
		}
	}
};

int main()
{

	Dogpi* d = new Dogpi();

	fan1* f1 = new fan1();
	fan2* f2 = new fan2();
	fan3* f3 = new fan3();
	// 关注up
	f1->uppers.push_back(d);
	f2->uppers.push_back(d);
	f2->uppers.push_back(d);

	// up添加粉丝（观察者）
	d->fans.push_back(f1);
	d->fans.push_back(f2);
	d->fans.push_back(f3);

	d->Update("2020-09-15");



	system("pause");
	return 0;
}