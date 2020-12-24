#include "cJSON.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

// ע�⣺ʹ��ʱֻҪ����cJSON.h �� cJSON.c�ļ�����ǰ��Ŀ����
// ����ͷ�ļ�#include "cJSON.h"
// ���������cJSON.c��Դ�ļ������򲻶Դ�����б��룬�����޷��ҵ���Ӧ�ĺ�����
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
	// ֻ�д洢�����Ǵ������ŵ��Ӷ��󣬻�����ʱ��ʹ��cJSON����
	cJSON *cjson_root = NULL;
	cJSON *cjson_address = NULL;
	cJSON *cjson_skill = NULL;

	// ����һ��JSON����
	cjson_root = cJSON_CreateObject();

	// ���key-value(string)
	cJSON_AddStringToObject(cjson_root, "name", "dogpi");

	// ���key-value(int)
	cJSON_AddNumberToObject(cjson_root, "age", 22);

	// ���key-value(double)
	cJSON_AddNumberToObject(cjson_root, "weight", 55.5);

	// ����һ��cJSON����
	cjson_address = cJSON_CreateObject();
	cJSON_AddStringToObject(cjson_address, "country", "China");
	cJSON_AddStringToObject(cjson_address, "detailed address", "̨��·3��");

	// ���key-value(cJSON)
	cJSON_AddItemToObject(cjson_root, "address", cjson_address);


	// ����һ��Array����
	cjson_skill = cJSON_CreateArray();
	cJSON_AddItemToArray(cjson_skill, cJSON_CreateString("C"));
	cJSON_AddItemToArray(cjson_skill, cJSON_CreateString("C++"));
	cJSON_AddItemToArray(cjson_skill, cJSON_CreateString("Python"));
	// ���key-value(cJSON_Array)
	cJSON_AddItemToObject(cjson_root, "skill", cjson_skill);

	// ���key-value(bool)
	cJSON_AddFalseToObject(cjson_root, "student");

	ofstream fd("./test.json");

	// ��ӡ
	cout << cJSON_Print(cjson_root) << endl;
	// ������ļ�
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