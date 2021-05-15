#include <iostream>
#include <cctype>
#include "modAlphaCipher.h"
#include <locale>
using namespace std;

void check(const wstring& Text, const wstring& key, const bool destructCipherText=false)
{
	try {
		wstring cipherText;
		wstring decryptedText;
		modAlphaCipher cipher(key);
		cipherText = cipher.encrypt(Text);
		if (destructCipherText)
			cipherText.front() = towlower(cipherText.front());
		decryptedText = cipher.decrypt(cipherText);
		wcout<<"key="<<key<<endl;
		wcout<<Text<<endl;
		wcout<<cipherText<<endl;
		wcout<<decryptedText<<endl;
	} catch (const cipher_error & e) {
		wcerr<<"Error: "<<e.what()<<endl;
	}
}
int main(int argc, char **argv)
{
	locale loc("ru_RU.UTF-8");
	locale::global(loc);
	check(L"ОБРАБОТКАИСКЛЮЧЕНИЙСРУССКИМАЛФАВИТОМ",L"Первый");
	check(L"ОБРАБОТКАИСКЛЮЧЕНИЙСРУССКИМАЛФАВИТОМ",L"");
	check(L"ОБРАБОТКАИСКЛЮЧЕНИЙСРУССКИМАЛФАВИТОМ",L"АБВГ123");
	check(L"ОБРАБОТКА ИСКЛЮЧЕНИЙ С РУССКИМ АЛФАВИТОМ",L"ВТОРОЙ");
	check(L"ОБРАБОТКАИСКЛЮЧЕНИЙСРУССКИМАЛФАВИТОМ",L"ТРЕТИЙ",true);
	check(L"123",L"АБВГ");
	return 0;
}
