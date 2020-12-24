#include <cstdio>
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;


int readFile_1();
int readFile_2();
int readFile_3();

int main()
{

	readFile_1();
	cout << "----------------------" << endl;
	readFile_2();
	cout << "----------------------" << endl;
	readFile_3();



	system("pause");
	return 0;
}

// 使用ifstream，通过设置偏移量获取文件大小，读取文件所有内容。
int readFile_1()
{
	ifstream fd;
	int length;
	fd.open("./test.txt");
	fd.seekg(0, ios::end);
	length = fd.tellg();
	fd.seekg(0, ios::beg);
	char *buffer = new char[length+1];
	memset(buffer, '\0', length + 1);
	fd.read(buffer, length);
	fd.close();

	cout << buffer << endl;
	delete[] buffer;
	return 0;
}

// 使用ifstreeam.rdbuf()读取文件所有内容，保存到stringstream中，最后把stringstream转换成char*
int readFile_2()
{
	ifstream fd;
	fd.open("./test.txt");
	stringstream str;
	str << fd.rdbuf();
	string buff(str.str());
	cout << buff << endl;
	return 0;
}

int readFile_3()
{
	FILE *fd;
	fd = fopen("./test.txt","r");
	fseek(fd, 0, SEEK_END);
	int length = ftell(fd);
	fseek(fd, 0, SEEK_SET);
	char *buff = new char[length];
	memset(buff, '\0', length);
	fread(buff, 1, length,fd);
	cout << buff << endl;
	delete[] buff;
	return 0;
}