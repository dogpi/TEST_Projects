#include <iostream>
#include <vector>
/*
�۲���ģʽ��
	���۲����ж����������۲���Ҳ��������Ӧ�ķ�Ӧ��
	Ҳ�������Ϊ�����ߺͶ����ߡ������߷�����Ϣ�������ߣ������߸�����Ϣ���д���

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
	// ֪ͨ�۲���
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
		std::cout << "�´�һ��" << std::endl;
	}
public:
	// ˢ�£��鿴��ע��up��û�и���
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
		std::cout << "�������� ����" << std::endl;
	}
public:
	// ˢ�£��鿴��ע��up��û�и���
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
		std::cout << "��Ŷ������������"<< std::endl;
	}
public:
	// ˢ�£��鿴��ע��up��û�и���
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
	// ��עup
	f1->uppers.push_back(d);
	f2->uppers.push_back(d);
	f2->uppers.push_back(d);

	// up��ӷ�˿���۲��ߣ�
	d->fans.push_back(f1);
	d->fans.push_back(f2);
	d->fans.push_back(f3);

	d->Update("2020-09-15");



	system("pause");
	return 0;
}