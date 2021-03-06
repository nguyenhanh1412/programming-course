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
#include <string>
using namespace std;



struct Word{
	string key;
	string val;
};
//объявить функции, используемые в данной программе
void printHelp();
void addNewPair(string key, string val, vector<Word>& dict);
void deletePair(string key, vector<Word>& dict);
bool checkPair(string key, vector<Word>& dict);
void printList(vector<Word>& dict);
void clearDict(vector<Word>& dict);
void sortDict(vector<Word>& dict);
void printDict(vector<Word>& dict);
void changePair(string key, string newVal, vector<Word>& dict);
void swapKeyVal(string key, vector<Word>& dict);

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

// Добавить новую пару в базу.
// Add a new pair into the Dict
void addNewPair(string key, string val, vector<Word>& dict) {
    dict.push_back({key, val});
}

// Удалить пару в базе
// Delete a pair in the dictionary
void deletePair(string key, vector<Word>& dict) {
    for (int i = 0; i < (int)dict.size(); i++) {
        if (key.compare(dict[i].key) == 0) {
            dict.erase(dict.begin() + i);
            break;
        }
    }
}

// Проверка существующей пары
// Check an existing pair
bool checkPair(string key, vector<Word>& dict) {
    bool flag = false;
    for (int i = 0; i < (int)dict.size(); i++) {
        if (key.compare(dict[i].key) == 0) {
            flag = true;
            break;
        }
    }
    return flag;
}


// Выводить список пары, у ключего слова которого есть меньше 5 символов.
// Print list of words that have lenght less than 5 symbols
void printList(string key, string val, vector<Word>& dict) {
	ofstream file;
	file.open("output.txt", ios::app);
	for(int i=0; i < (int)dict.size(); i++){
		if (dict[i].key.size() <= 5) {
			file << dict[i].key <<": ";
			file << dict[i].val << endl;
		}
		
	}
	file.close();
    /*for (int i = 0; i < (int)dict.size(); i++) {
        if (dict[i].key.size() < 5)
            My << dict[i].key << " => " << dict[i].val << endl;
    }*/
}

// Очистить словарь
// Clear the dictionary
void clearDict(vector<Word>& dict) {
    dict.clear();
}

// Сортировать словарь
// Sort the dictionary
void sortDict(vector<Word>& dict) {
    Word temp;
    for (int i = 0; i < (int)dict.size(); i++) {
        for(int j= 0; j < (int)(dict.size() - 1); j++) {
            if (dict[j].key.compare(dict[j+1].key) > 0) {
                temp = dict[j];
                dict[j] = dict[j+1];
                dict[j+1] = temp;
            }
        }
    }
}

// Выводить весь словарь
// 
void printDict(vector<Word>& dict) {
    for (int i = 0; i < (int)dict.size(); i++)
        cout << dict[i].key << " => " << dict[i].val << endl;
    cout << endl;
	//outputFile (key, val, Dict);

}

// Изменять пары
// Change the pair
void changePair(string key, string newVal, vector<Word>& dict) {
	for (int i = 0; i < (int)dict.size(); i++) {
		if (key.compare(dict[i].key) == 0) {
			dict[i].val = newVal;
			break;
		}
	}
}

// Обменять ключом и значением.
// Swap the key and the value
void swapKeyVal(string key, vector<Word>& dict) {
	string temp;
	for (int i = 0; i < (int)dict.size(); i++) {
		if (key.compare(dict[i].key) == 0) {
			temp = dict[i].val;
			dict[i].key = temp;
			dict[i].val = key;
			break;
		}
	}
}
//
void outputFile(string key, string val, vector<Word>& dict){
	ofstream file;
	file.open("output.txt", ios::app);
	for(int i=0; i < (int)dict.size(); i++){
		file << dict[i].key <<": ";
		file << dict[i].val << endl;
	}
	file.close();
}

int main() {
	printHelp();
	vector<Word> Dict;
	fstream text;
	text.open("D:/eclipse-workspace/Lab_6/src/input.txt");

	// Create and open a text file
	ofstream MyFile("output.txt", ios::app);
	//MyFile.open("output.txt", ios::app);
	//string line;
	string key;
	string val;
	while(!text.eof()){
		text >> key >> val;
		Word temp;
		temp.key =  key;
		temp.val = val;
		Dict.push_back(temp);
	}
	text.close();

    int choice;
    while (true) {

    	cout << "\nEnter your choice: ";
    	cin >> choice;

    	switch(choice) {
    	case 1:
    		//Add a new pair
    		cout << "Enter a key: ";
    		cin >> key;
    		cout << "Enter a value: ";
    		cin >> val;
    		addNewPair(key, val, Dict);
    		MyFile << "++ Add a new pair" << endl;
    		outputFile (key, val, Dict);
    		//printDict(Dict);
    		cout << endl;
    		break;

    	case 2:
    		//clearDict(Dict);
    		
    		cout << "Enter a key: ";
    		cin >> key;
    		deletePair(key, Dict);
			MyFile << endl << "++ Delete an existing pair" <<endl;
    		outputFile (key, val, Dict);
    		break;
    	case 3:
    		//
    		// Cheking a pair
    		cout << "Enter a key: ";
    		cin >> key;
    		if (checkPair(key, Dict)) {
    			MyFile << endl << "++ This word was found" << endl;
    			
    		} else {
    			MyFile << endl << "++ This pair was not found" <<endl;
    			
    		}
    		break;
    	case 4:
    		//clearDict(Dict);

    		MyFile <<endl << "++ Print a list of words that have lenght less than 5" << endl;

    		printList(key, val, Dict);
    		
    		break;
    	case 5:
    		//Clear dictionary
    		clearDict(Dict);
    		MyFile << endl << "++ Clear dictionary" <<endl;
    		outputFile (key, val, Dict);
    		//printDict(Dict);
    		break;
    	case 6:
    		//clearDict(Dict);
    		// Sort Dictionary
    		sortDict(Dict);
    		MyFile << endl << "++ Sort Dictionary" <<endl;
    		outputFile (key, val, Dict);
    		//printDict(Dict);
    		break;
    	case 7:
    		//clearDict(Dict);
    		//Print dictionary
    		//printDict(Dict);
    		MyFile <<endl << "++ Print dictionary" <<endl;
    		outputFile (key, val, Dict);
    		break;
    	case 8:
    		//Change a pair
    		cout << "Enter a key: ";
    		cin >> key;
    		cout << "Enter new value: ";
    		cin >> val;
    		changePair(key,val, Dict);
    		MyFile << endl << "++ Change a pair" <<endl;
			//printDict(Dict);
    		outputFile (key, val, Dict);
			//outputFile (key, val, Dict);

    		break;
    	case 9:
    		//Swap Key and Value
    		cout << "Enter a key:";
    		cin >> key;
    		swapKeyVal(key, Dict);
    		MyFile << endl << "++ Swap Key and Value" <<endl;
			//printDict(Dict);
    		outputFile (key, val, Dict);
    		break;
    	default:
    		printHelp();
    		break;
    	}
    }

    return 0;
}





