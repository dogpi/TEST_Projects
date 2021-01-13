#include <iostream>
using namespace std;

class A
{
public:
	A()
		:n2(0),
		n1(n2 + 2)
	{}

	//~A();

	void print()
	{
		cout << "n1:" << n1 << " ,  n2:" << n2 << endl;
	}

private:
	int n1;
	int n2;
};

//A::~A()
//{
//}
int main()
{
	A a;
	a.print();
	system("pause");
	return 0;
}