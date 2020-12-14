#include <iostream>
#include <Windows.h>


using namespace std;

typedef void(*printEWL)(const char*);

int main()
{
	printEWL printERROR, printWARNING, printLOG;
	HINSTANCE dllInstance= LoadLibrary("CreateDll.dll");
	if (NULL == dllInstance) {
		cout << "load dll failed" << endl;
		system("pause");
		return -1;
	}
	printERROR = (printEWL)GetProcAddress(dllInstance, "printERROR");
	printERROR("��ӡERROR");

	printWARNING = (printEWL)GetProcAddress(dllInstance, "printWARNING");
	printWARNING("��ӡWARNING");
	
	printLOG = (printEWL)GetProcAddress(dllInstance, "printLOG");
	printLOG("��ӡLOG");
	
	FreeLibrary(dllInstance);
	system("pause");
	return 0;
}