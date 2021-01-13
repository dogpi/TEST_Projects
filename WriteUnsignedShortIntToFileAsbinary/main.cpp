#include <fstream>
#include <iostream>
#include <stdio.h>


using namespace std;

int main()
{
	FILE * fd = fopen("./binary.bin", "wb");


	unsigned short int val = 0x11FF;
	fwrite(&val, sizeof(unsigned short int), 1, fd);

	fclose(fd);


	system("pause");
	return 0;
}