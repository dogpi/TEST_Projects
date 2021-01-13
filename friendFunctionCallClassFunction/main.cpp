#include <iostream>

using namespace std;

class Test{
public:
	string name;
	int age;

	void print(){
		cout << "Hello, world!" << endl;
	}

	friend void friendFunction(Test t);

private:
	int weight=10;
};

void friendFunction(Test t)
{
	t.print();
}


int main()
{
	Test t;
	friendFunction(t);

	system("pause");
	return 0;
}
