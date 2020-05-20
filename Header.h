/**
* @file
* @brief класс хранит данные о жильцах жилищного комплекса
* присутствуют перегрузки операторов
* @author Фомин Андрей
*/

#pragma once
#include <string>
#include"HashFunctions.h"
#include <vector>

namespace mySpace {
	class OurClass {
	private:
		int home;					// поле хранит номер дома
		int flat;					// поле хранит номер квартиры
		int room;					// поле хранит число комнат
		int square;					// поле хранит площадь квартиры
		int people;					// поле хранит число людей, живущих в квартире
		std::string fio;			// поле хранит ФИО владельца квартиры
		unsigned long long hash;	// поле хранит хеш-код ФИО
	public:
		
		/**
		* Публичный конструктор класса,
		* принимает на вход строку и парсит ее по полям
		* @param Ссылка на строку, которую нужно распарсить
		* @option Определяет, какую хеш-функцию использовать
		* для строки
		*/
		OurClass(const std::string& str, int option) {
			std::vector<std::string> v;
			int size = str.size();
			int left = 0;
			int right;
			int numspace = 5;
			for (int i = 0; i < size; i++) {
				if (str[i] == ' ' && numspace > 0) {
					right = i;
					v.push_back(str.substr(left, right - left));
					left = i + 1;
					numspace--;
				}
			}
			home = std::stoi(v[0]);
			flat = std::stoi(v[1]);
			room = std::stoi(v[2]);
			square = std::stoi(v[3]);
			people = std::stoi(v[4]);
			fio = str.substr(left);
			if (option == 0) {
				hash = badHash(fio);
			}
			if (option == 1) {
				hash = goodHash(fio);
			}
		}

		/**
		* Пустой конструктор
		*/
		OurClass() {
			home = 0;
			flat = 0;
			square = 0;
			fio = "";
			people = 0;
			room = 0;
			hash = 0;
		};


		/**
		* Возвращает номер дома жильца
		* @return int Возвращает номер дома
		*/
		int getHome() {
			return home;
		}


		/**
		* Возвращает номер квартиры
		* @return int Возвращает номер квартиры
		*/
		int getFlat() {
			return flat;
		}


		/**
		* Возвращет площадь квартиры
		* @return int Площадь квартиры
		*/
		int getSquare() {
			return square;
		}


		/**
		* Возвращает число людей, проживающих в квартире
		* @return int Число людей в квартире
		*/
		int getPeople() {
			return people;
		}


		/**
		* Возвращает ФИО владелья квартиры
		* @return string Владелец квартиры
		*/
		std::string getFio() {
			return fio;
		}


		/**
		* Возвращает всю строку, со всеми данными, которую
		* получил конструктор
		* @return string Строка, со всеми данными
		*/
		std::string AllString() {
			return std::to_string(home) + " " + std::to_string(flat) + " " + std::to_string(room) + " " + std::to_string(square) + " " +
				std::to_string(people) + " " + fio;
		}


		/**
		* Возвращает хеш-код объекта - ФИО владельца квартиры
		* @return unsigned long long - хеш-код строки - ФИО владельца квартиры
		*/
		unsigned long long getHash() {
			return hash;
		}

		 
		friend bool operator>(const OurClass& left, const OurClass& right) {
			if ((left.fio > right.fio)) {
				return true;

			}
			else
				return false;
		}


		// перегрузка оператора сравнения БОЛЬШЕ ИЛИ РАВНО
		friend bool operator>=(const OurClass& left, const OurClass& right) {
			if ((left.fio > right.fio) || (left.fio == right.fio)) {
				return true;

			}
			else
				return false;
		};


		// перегрузка оператора МЕНЬШЕ
		friend bool operator<(const OurClass& left, const OurClass& right) {
			if (left.fio < right.fio) {
				return true;

			}
			else
				return false;
		};


		//перегрузка оператора МЕНЬШЕ ИЛИ РАВНО
		friend bool operator<=(const OurClass& left, const OurClass& right) {
			if ((left.fio < right.fio) || (left.fio == right.fio)) {
				return true;

			}
			else
				return false;
		};

	}; // end our_class
} // end namespace N
