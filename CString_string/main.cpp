#include <iostream>
#include <string>



int main()
{
	std::string s("hello");

	// 不加头文件string要将s转成c_str()才能打印
	//std::cout << s.c_str() << std::endl;
	std::cout << s << std::endl;
	system("pause");
	return 0;
}