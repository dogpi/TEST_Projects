#include "cJSON.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

// 注意：使用时只要拷贝cJSON.h 和 cJSON.c文件到当前项目即可
// 包含头文件#include "cJSON.h"
// 添加现有想cJSON.c到源文件，否则不对代码进行编译，导致无法找到对应的函数。
int createJsonFile();
int parseJsonFile();

int main()
{
	createJsonFile();
	parseJsonFile();

	system("pause");
	return 0;
}

int createJsonFile()
{
	// 只有存储对象是带大括号的子对象，或数组时才使用cJSON对象
	cJSON *cjson_root = NULL;
	cJSON *cjson_address = NULL;
	cJSON *cjson_skill = NULL;

	// 创建一个JSON对象
	cjson_root = cJSON_CreateObject();

	// 添加key-value(string)
	cJSON_AddStringToObject(cjson_root, "name", "dogpi");

	// 添加key-value(int)
	cJSON_AddNumberToObject(cjson_root, "age", 22);

	// 添加key-value(double)
	cJSON_AddNumberToObject(cjson_root, "weight", 55.5);

	// 创建一个cJSON对象
	cjson_address = cJSON_CreateObject();
	cJSON_AddStringToObject(cjson_address, "country", "China");
	cJSON_AddStringToObject(cjson_address, "detailed address", "台虹路3号");

	// 添加key-value(cJSON)
	cJSON_AddItemToObject(cjson_root, "address", cjson_address);


	// 创建一个Array对象
	cjson_skill = cJSON_CreateArray();
	cJSON_AddItemToArray(cjson_skill, cJSON_CreateString("C"));
	cJSON_AddItemToArray(cjson_skill, cJSON_CreateString("C++"));
	cJSON_AddItemToArray(cjson_skill, cJSON_CreateString("Python"));
	// 添加key-value(cJSON_Array)
	cJSON_AddItemToObject(cjson_root, "skill", cjson_skill);

	// 添加key-value(bool)
	cJSON_AddFalseToObject(cjson_root, "student");

	ofstream fd("./test.json");

	// 打印
	cout << cJSON_Print(cjson_root) << endl;
	// 输出到文件
	fd << cJSON_Print(cjson_root);
	fd.close();
	return 0;
}

int parseJsonFile()
{
	cJSON *cjson_root = NULL;
	cJSON *cjson_name = NULL;
	cJSON *cjson_age = NULL;
	cJSON *cjson_weihtt = NULL;
	cJSON *cjson_address = NULL;
	cJSON *cjson_address_Country = NULL;
	cJSON *cjson_address_detailed_address = NULL;
	cJSON *cjson_skill_array = NULL;


	ifstream f("./test.json");
	stringstream str;
	str<<f.rdbuf();

	cjson_root = cJSON_Parse(str.str().c_str());
	if (cjson_root == NULL)
	{
		cout << "parse fail" << endl;
		return -1;
	}

	cjson_name = cJSON_GetObjectItem(cjson_root, "name");
	cjson_age = cJSON_GetObjectItem(cjson_root, "age");
	cjson_weihtt = cJSON_GetObjectItem(cjson_root, "weight");

	cout << "name: " << cjson_name->valuestring << endl;
	cout << "age: " << cjson_name->valuestring << endl;
	cout << "weight: " << cjson_weihtt->valuedouble << endl;
	
	cjson_address = cJSON_GetObjectItem(cjson_root, "address");
	cjson_address_Country = cJSON_GetObjectItem(cjson_address, "country");
	cjson_address_detailed_address = cJSON_GetObjectItem(cjson_address, "detailed address");

	cout << "country: " << cjson_address_Country->valuestring << endl;
	cout << "detailed address: " << cjson_address_detailed_address->valuestring << endl;


	return 0;
}