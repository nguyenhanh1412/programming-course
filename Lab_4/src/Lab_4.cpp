#include <iostream>
#include <vector>
#include <utility>

using namespace std;

void printHelp();
void addNewPair(string key, string val, vector<pair<string, string>>& array);
void deletePair(string key, vector<pair<string, string>>& array);
bool checkPair(string key, vector<pair<string,string>>& array);
void printList(vector<pair<string,string>>& array);
void clearDict(vector<pair<string,string>>& array);
void sortDict(vector<pair<string,string>>& array);
void printDict(vector<pair<string, string>>& array);
void changePair(string key, string newVal, vector<pair<string,string>>& array);
void swapKeyVal(string key, vector<pair<string,string>>& array);



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

// Add a new pair into the database
void addNewPair(string key, string val, vector<pair<string, string>>& array) {
    array.push_back({key, val});
}

// Delete a pair in the dictionary
void deletePair(string key, vector<pair<string, string>>& array) {
    for (int i = 0; i < (int)array.size(); i++) {
        if (key.compare(array[i].first) == 0) {
            array.erase(array.begin() + i);
            break;
        }
    }
}

// Check an existing pair
bool checkPair(string key, vector<pair<string,string>>& array) {
    bool flag = false;
    for (int i = 0; i < (int)array.size(); i++) {
        if (key.compare(array[i].first) == 0) {
            flag = true;
            break;
        }
    }
    return flag;
}

// Print list of words that have lenght less than 5 symbols
void printList(vector<pair<string,string>>& array) {
    for (int i = 0; i < (int)array.size(); i++) {
        if (array[i].first.size() < 5)
            cout << array[i].first << " => " << array[i].second << endl;
    }
}

// Clear the dictionary
void clearDict(vector<pair<string,string>>& array) {
    array.clear();
}

// Sort the dictionary
void sortDict(vector<pair<string,string>>& array) {
    pair<string,string> temp;
    for (int i = 0; i < (int)array.size(); i++) {
        for(int j=0; j < (int)(array.size() - 1); j++) {
            if (array[j].first.compare(array[j+1].first) > 0) {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

// Print the whole dictionary
void printDict(vector<pair<string, string>>& array) {
    for (int i = 0; i < (int)array.size(); i++)
        cout << array[i].first << " => " << array[i].second << endl;

    cout << endl;
}

// Change the pair
void changePair(string key, string newVal, vector<pair<string,string>>& array) {
	for (int i = 0; i < (int)array.size(); i++) {
		if (key.compare(array[i].first) == 0) {
			array[i].second = newVal;
			break;
		}
	}
}

// Swap the key and the value
void swapKeyVal(string key, vector<pair<string,string>>& array) {
	string temp;
	for (int i = 0; i < (int)array.size(); i++) {
		if (key.compare(array[i].first) == 0) {
			temp = array[i].second;
			array[i].first = temp;
			array[i].second = key;
			break;
		}
	}
}


int main() {
	printHelp();

    vector<pair<string, string>> database;

    database.push_back({"mouse", "мышь"});
    database.push_back({"buffallo", "бык"});
    database.push_back({"tiger", "тигр"});
    database.push_back({"cat", "кот"});
    database.push_back({"dragon", "дракон"});
    database.push_back({"snake", "змея"});
    database.push_back({"horse", "лошадь"});
    database.push_back({"goat", "коза"});
    database.push_back({"monkey", "обезьяна"});
    database.push_back({"chicken", "петух"});
    database.push_back({"dog", "собака"});
    database.push_back({"pig", "свинья"});

    string key;
    string val;
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
    		addNewPair(key, val, database);
    		printDict(database);
    		cout << endl;
    		break;
    	case 2:
    		// Delete an existing pair
    		cout << "Enter a key: ";
    		cin >> key;
    		deletePair(key, database);
    		printDict(database);
    		cout << endl;
    		break;
    	case 3:
    		// Cheking a pair
    		cout << "Enter a key: ";
    		cin >> key;
    		if (checkPair(key, database)) {
    			cout << "This pair was found\n";
    		}else{
    			cout<<"This pair was not found\n";
    		}
    		break;
    	case 4:
    		// Print a list of words that have lenght less than 5
    		printList(database);
    		break;
    	case 5:
    		//Clear dictionary
    		clearDict(database);
    		printDict(database);
    		break;
    	case 6:
    		// Sort Dictionary
    		sortDict(database);
    		printDict(database);
    		break;
    	case 7:
    		//Print dictionary
    		printDict(database);
    		break;
    	case 8:
    		//Change a pair
    		cout << "Enter a key: ";
    		cin >> key;
    		cout << "Enter new value: ";
    		cin >> val;
    		changePair(key,val, database);
    		printDict(database);
    		break;
    	case 9:
    		//Swap Key and Value
    		cout << "Enter a key:";
    		cin >> key;
    		swapKeyVal(key, database);
    		printDict(database);
    		break;
    	default:
    		printHelp();
    		break;
    	}
    }

    return 0;
}
