//============================================================================
// Name        : Lab_6.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct Word{
	string key;
	string val;
};
//объявить функции, используемые в данной программе
void addNewPair(string key, string val, struct Word& dict);



// Add a new pair into the Dict
void addNewPair(string key, string val, vector <Word>& dict) {
    dict.push_back({key, val});
}
int main() {
	string key, val;
	vector<Word> Dict;
    //Add a new pair
    cout << "Enter a key: ";
    cin >> key;
    cout << "Enter a value: ";
    cin >> val;
    addNewPair(key, val, Dict);
    cout << endl;

    return 0;
}
