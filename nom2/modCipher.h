#pragma once
#include <vector>
#include <string>
#include <iostream>
class modCipher
{
private:
	int key;
	int getValidKey(const int key, const std::wstring & s);
	std::wstring getValidOpenText(const std::wstring & s);
	std::wstring getValidCipherText(const std::wstring & s);
public:
	modCipher()=delete; //запретим конструктор без параметров
	modCipher(int k); //конструктор для установки ключа
	std::wstring encrypt(modCipher key, std::wstring& open_text); //зашифрование
	std::wstring decrypt(modCipher key, std::wstring& cipher_text);//расшифрование
};
class cipher_error: public std::invalid_argument
{
public:
	explicit cipher_error (const std::string& what_arg):
		std::invalid_argument(what_arg) {}
	explicit cipher_error (const char* what_arg):
		std::invalid_argument(what_arg) {}
};
