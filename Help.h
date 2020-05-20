/**
* @file
* @brief Вспомогательная функция
* @author Фомин Андрей
*/

#pragma once
#include "Header.h"
#include "HashTable.h"
using namespace std;
using namespace mySpace;


/**
* Функция создает хеш-таблицу, заполняет ее элементами, 
* производит поиск нужного элемента
* выводит результаты поиска в консоль
* @param Data Ccылка на вектор, содержащий элементы типа OurClass
* этими элементами заполняется хеш-таблица
* @param key Ссылка на строку, по которой производится поиск
* @param length Число объектов, которыми заполняется хеш-таблица
* @param option Значения определяет, какая хеш-функция будет использоваться 
* для поиска
* @return ничего
*/
void helpToFind(vector<OurClass> & Data, string & key, int length, int option) {
	hashTable table;
	for (int i = 0;i < length;i++) {
		table.add(Data[i]);
	}
	table.find(key, option);
	table.getNumberOfCollusions();
}
