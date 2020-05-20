/**
* @file 
* @brief заголовочный файл с двумя хеш-функциями:
* "хорошей" и "плохой"
* @author Фомин Андрей
*/



#pragma once
#include <string>
/**
*public-функция
* "плохая" хеш-функция. Возвращает хеш-код параметра key
* хеш-значение считается как сумма кодов по таблице ASCII
* всех символов строки
*
* @param key ссылка на строку, для которой считается хеш-код
* @return unsigned long long - хеш-код переданного ключа
*/
unsigned long long badHash(std::string& key) {
	unsigned long long hash = 0;
	for (int i = 0; i < key.length(); i++) {
		hash += static_cast<unsigned char>(key[i]);
	}
	return hash;
}

/**
* public-функция
* "хорошая хеш-функция". Функция реализует алгоритм хеш-функции
* rot13
*
* @param key Cсылка на строку, для которой считается хеш-код
* @return unsigned long long {еш-код ключа
*/
unsigned long long goodHash(std::string & key){
	unsigned long long hash = 0;
	for (int i = 0; i < key.length();i++) {
		hash = (hash * 2) + ((unsigned char)key[i])*2;
	}
	return hash;
}
