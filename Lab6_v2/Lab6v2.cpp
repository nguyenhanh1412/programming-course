#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <bits/stdc++.h>

using namespace std;


struct Word{
	string key;
	vector<string> val;
};

void splitString (string str, vector<string>& lineArr);
void addNewPair(string key, vector<string> val, vector<Word>& dict);
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

//1. Add a new pair into the Dict
void addNewPair(string key, vector<string> val, vector<Word>& dict) {
    Word temp;
    temp.key = key;
    for(int i = 0; i < (int)val.size(); i++){
        temp.val.push_back(val.at(i));
    }
    dict.push_back(temp);
}

//2. Delete a pair in the dictionary
void deletePair(string key, vector<Word>& dict) {
    for (int i = 0; i < (int)dict.size(); i++) {
        if (key.compare(dict[i].key) == 0) {
            dict.erase(dict.begin() + i);
            break;
        }
    }
}

//3. Check an existing pair
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

//4. Print list
void printList(string key, vector<string> val, vector<Word>& dict) {
    ofstream file;
	file.open("output.txt", ios::app);
	for(int i=0; i < (int)dict.size(); i++){
		if (dict[i].key.size() < 5) {
			file << dict[i].key <<": ";
            for (int j = 0; j < (int)dict[i].val.size(); j++){
                file << dict[i].val[j] << " ";
            }
            file << endl;	    
        }	
	}
}

//5. Clear the dictionary
void clearDict(vector<Word>& dict) {
    dict.clear();
}

//6. Sort dictionary
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

//7. Print the whole dictionary
//8. Change the pair
void changePair(string key, vector<string> newVal, vector<Word>& dict) {
	for (int i = 0; i < (int)dict.size(); i++) {
		if (key.compare(dict[i].key) == 0) {
            dict[i].val.clear();
            for(int j = 0; j < (int)newVal.size(); j++){
                dict[i].val.push_back(newVal[j]);
            }
			break;
		}
	}
}

//9. Swap the key and the value
void swapKeyVal(string key, vector<Word>& dict) {
	Word temp;
	for (int i = 0; i < (int)dict.size(); i++) {
		if (key.compare(dict[i].key) == 0) {
            for(int j = 0; j < (int)dict[i].val.size(); j++){
			    temp.key = dict[i].val[j];
                temp.val.push_back(dict[i].key);
                dict.push_back(temp);
                temp.val.clear();
            }
			break;
		}
	}
}

//Split string
void splitString (string str, vector<string>& lineArr){
     istringstream ss(str);
     string temp;
     while (ss >> temp) {
         lineArr.push_back(temp);
    }
}

void outputFile(vector<Word>& dict){
	ofstream file;
	file.open("output.txt", ios::app);
	for(int i=0; i < (int)dict.size(); i++){
		file << dict[i].key <<": ";
        for(int j = 0; j < dict[i].val.size(); j++){
            file << dict[i].val[j] << " ";
        }
        file << endl;
	}
    file << "------------------------------------------------------" << endl << endl; 
	file.close();

}


int main() {
    printHelp();
    vector<Word> Dict;
	fstream textIn;
	textIn.open("D:/C++/Lab6_v2/input.txt");

	// Create and open a text file
	ofstream textOut("output.txt", ios::app);
	//MyFile.open("output.txt", ios::app);
	//string line;
	string key;
	vector<string> val;
    string input;
    vector<string> lineArr;
    string str;
    while(!textIn.eof()){
        getline(textIn, input);
        //cout << input << endl;
        splitString(input, lineArr);
        Word temp;
        temp.key = lineArr[0];
        for (int i=1; i < (int)lineArr.size(); i++){
            temp.val.push_back(lineArr[i]);
        }
        lineArr.clear();
        Dict.push_back(temp);
    }

    int choice;
    while (true) {

    	cout << "\nEnter your choice: ";
    	cin >> choice;

    	switch(choice) {
    	case 1:
    		//Add a new pair
            textOut << "Add a new word" << endl;
            cin.ignore();
    		cout << "Enter a key: ";
    		getline(cin, key);
            cout << "Enter vals: ";
            getline(cin, str);
            splitString(str, lineArr);
    		addNewPair(key, lineArr, Dict);
            outputFile(Dict);
            lineArr.clear();

    		break;
        case 2:
    		//clearDict(Dict);
    		textOut << "Clear a word" << endl;
    		cout << "Enter a key: ";
    		cin >> key;
    		deletePair(key, Dict);
    		outputFile (Dict);
    		break;
        case 3:
    		// Cheking a pair
    		cout << "Enter a key: ";
    		cin >> key;
    		if (checkPair(key, Dict)) {
    			textOut << "This word was found" << endl << "----------------------------------------" <<endl;
    			
    		} else {
    			textOut <<"This pair was not found" <<endl<< "----------------------------------------" <<endl;
    			
    		}
    		break;

        case 4:
    		//clearDict(Dict);
            textOut << "Print a list of words that have lenght less than 5" << endl;
    		printList(key, val, Dict);
    		
    		break;
        case 5:
    		//Clear dictionary
    		clearDict(Dict);
    		textOut << "Clear dictionary" <<endl;
    		outputFile (Dict);
    		break;
        case 6:
            sortDict(Dict); 
            textOut << "Sort dictionary";
            outputFile (Dict);
        case 7:
            textOut << "Whole dictionary" <<endl;
            outputFile (Dict);
            break;
        case 8:
    		//Change a pair
            textOut << "Change a word" <<endl;
            cin.ignore();
    		cout << "Enter a key: ";
    		getline(cin, key);
            cout << "Enter new vals: ";
            getline(cin, str);
            splitString(str, lineArr);
    		changePair(key, lineArr, Dict);
            outputFile (Dict);
    		break;

        case 9:
    		//Swap Key and Value
            textOut << "Swap a word" <<endl;
    		cout << "Enter a key:";
    		cin >> key;
    		swapKeyVal(key, Dict);
    		outputFile (Dict);
    		break;
        default:
            break;
        }
    }
	textIn.close();

    return 0;
}
