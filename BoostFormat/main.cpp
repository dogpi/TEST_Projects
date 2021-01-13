#include <boost/format.hpp>
#include <iostream>
#include <string>

int main(){
	float fData = 4096.0;
	char hexData[8] = { 0 };

	sprintf_s(hexData, "0x%x", (int)fData);

	std::cout << boost::format("%s") % hexData << std::endl;
	system("pause");
	return 0;
}
