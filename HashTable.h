/**
* @file
* @brief Реализация хеш-таблицы,
* с помощью unordered_map, где key - хеш значение объекта
* value - вектор с обьектами, имеющими одинаковый хеш-код
* @author Фомин Андрей
*/

#pragma once
#include "Header.h"
#include "HashFunctions.h"
#include <unordered_map>
#include <ctime>
using namespace std;

namespace mySpace {
	class hashTable {
	private:
		unsigned long long numberOfElements;
		unordered_map<unsigned long long, vector<OurClass>> table;
	public:
		/**
		* public-функция
		* Добавляет в хеш-таблицу переданный в качестве аргумента объект
		* @param object - ссылка на объект типа OurClass
		* @return ничего
		*/
		void add(OurClass& object) {
			numberOfElements += 1;
			auto it = table.find(object.getHash());
			if (it == table.end()) {
				std::vector<OurClass>v;
				v.push_back(object);
				table.emplace(object.getHash(), v);
			}
			else {
				it->second.push_back(object);
			}
		}
		/**
		* public-функция
		* Ищет объект, содержащий данную строку
		* от option зависит, какую хеш-функцию используем для поиска
		* выводит в консоль время поиска, результаты, количество всех элементов
		* @param key - ссылка на строку, что мы хотим найти
		* @param option - определяет, какую хеш-функцию мы используем
		* для поиска
		* @return ничего
		*/
		void find(string& key, int option) {
			unsigned long long hash;
			vector<OurClass> Found;
			double start = clock();
			//если 0, то плохая функция
			if (option == 0) hash = badHash(key); 
			//если 1, то хорошая функция
			if (option == 1) hash = goodHash(key);
			auto search = table.find(hash);
			if (search != table.end()) {
				for (int i = 0; i < search->second.size();i++) {
					if (search->second[i].getFio() == key) {
						Found.push_back(search->second[i]);
					}
				}
			}
			double end = clock();
			cout << "n = " << numberOfElements << " время поиска: " << end - start << " в миллисекундах" << "\n";
			cout << "Мы искали: " << key << "\n";
			if (Found.size() > 0) {
				cout << "Нашлось:\n";
				for (int i = 0; i < Found.size();i++) {
				cout << "\t" << Found[i].AllString() << "\n";
				}
			}
			else {
				cout << "Ничего не нашлось\n";
			}
			cout << "---------------------------------------------------------------------\n";
		}
		/**
		* public-функция
		* выводит в консоль количество всех элементов в хеш-таблице
		* @return ничего
		*/
		void getNumberOfElements() {
			cout << "Количество элементов: " << numberOfElements << "\n";
		}


		/**
		* Выводит в консоль число корзин
		* @return ничего
		*/
		void getNumberOfBuckets() {
			cout << table.size() << "\n";
		}
		

		/**
		* Считает колличество коллизий, выводит в консоль
		* @return ничего
		*/
		void getNumberOfCollusions() {
			int numberOfCollusions = 0;
			auto it = table.begin();
			for (it; it != table.end();it++) {
				if (it->second.size() > 1) {
					numberOfCollusions += it->second.size();
				}
			}
			cout << numberOfCollusions << "\n";
		}
	};
}
