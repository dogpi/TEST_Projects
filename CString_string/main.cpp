#include <iostream>
#include <string>



int main()
{
	std::string s("hello");

	// ����ͷ�ļ�stringҪ��sת��c_str()���ܴ�ӡ
	//std::cout << s.c_str() << std::endl;
	std::cout << s << std::endl;
	system("pause");
	return 0;
}