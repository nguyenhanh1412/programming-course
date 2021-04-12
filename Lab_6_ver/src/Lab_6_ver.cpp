//============================================================================
// Name        : Lab_6_ver.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
using namespace std;
//объявить функции, используемые в данной программе
void printHelp();






struct Word{
	string key;
	string val;
};




void printHelp() {
    cout << "WELCOME TO A SIMPLE DICTIONARY!!!\n";
    cout << "Enter 1 to add a new pair\n";
    cout << "Enter 2 to delete a pair\n";
    cout << "Enter 3 to check an existing pair\n";
    cout << "Enter 4 to print a list of pairs that have length less than 5 symbols";
    cout << "Enter 5 to clear the dictionary\n";
    cout << "Enter 6 to sort the dictionary\n";
    cout << "Enter 7 to print the dictionary\n";
    cout << "Enter 8 to change a pair in the dictionary\n";
    cout << "Enter 9 to swap key and value\n";
}



void addNewPair (string key, string val, )



int main() {
	printHelp();
	struct Word Dict[100];
	fstream text;
	text.open("D:/eclipse-workspace/Lab_6/text.txt");

	string line;
	string key;
	string val;
	int i = 0;
	while(!text.eof()){
		text >> key >> val;
		//cout << key <<":" << val <<endl;
		Dict[i].key = key;
		Dict[i].val = val;
		i++;
	}
	//cout << Dict[2].key << ": " << Dict[2].val;
	text.close();



	return 0;
}
