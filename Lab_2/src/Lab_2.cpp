//============================================================================
// Name        : Lab_2.cpp
// Author      : Nguyen Hanh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

bool Palindrome(string s){
	// создание функции, которая возвращает полиндром ли является строка "s"
	// если строка полиндром, то строка симетричная
	// создание временной строки "temp", которая начинается с конца до половины строки "s"
	// сравнение строки "temp" с первой половиной строки "s"

	string temp;
	int s_len = s.size();
	for(int i = 0; i < (s_len)/2; i++){
		temp.push_back(s[s_len-1-i]); // Добавление символа в конец строки
	}

	if(temp.compare(s.substr(0, s_len/2)) != 0){ // substr -- для получнения подстроки от позиции 0 с длиной s_len/2
		return false;
	}
	else{
		return true;
	}
}

int main() {
	cout << "Enter a string: ";
	string s;
	cin >> s;
	if(Palindrome(s)){

		cout<<"String is Palindrome";
	}
	else{
		cout <<"String is not Palindrome";
	}
	return 0;
}
