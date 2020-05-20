#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "Header.h"
#include "HashTable.h"
#include "Help.h"
using namespace std;
using namespace mySpace;

int main()
{
	setlocale(LC_ALL, "Russian");
	vector<OurClass> Data;
	ifstream In("D:\\УЧЕБА\\Методы программирования\\19var\\DataCpp.txt");
	string str;
	while (!In.eof())
	{
		getline(In, str);
		Data.push_back(OurClass(str,1));
	}
	string key1 = "Авандеев Вольдемар Рудольфович";
	string key2 = "Ковалев Родион Наумович";
	string key3 = "Гринин Тимофей Зиновьевич";
	hashTable myTable;
	/*int dev[] = { 100,1000,5000,10000,20000, 50000,70000,Data.size() };
	for (int i = 0; i < 8;i++) {
		helpToFind(Data, key3, dev[i], 0);
	}*/
}
