#include <iostream>
#include <sstream>
using namespace std;


int main(){

	int d_value = 100;
	cout << "ʮ�����ƣ�"<<hex << d_value <<dec<<" ʮ���ƣ�"<<d_value<< endl;

	// toHexString
	stringstream hexString;
	hexString <<"0x"<< hex << d_value;
	cout << hexString.str() << endl;

	// HexStringToInt
	stringstream dString;
	int value;
	dString << hex << "1A";
	dString >> value;
	cout << value << endl;

	string hexStr = "1A";
	int x = stoi(hexStr, nullptr, 16);
	cout << x << endl;

	system("pause");
	return 0;
}