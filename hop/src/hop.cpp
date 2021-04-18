//============================================================================
// Name        : hop.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	for(int i = 2565; i < 2596; i += 2){
		for(int j = 11; j < 2596; j += 2){
			if( i % j == 0 && i % 3 != 0 && i % 5 != 0 && i % 7 != 0){
				cout << "so: " << i << endl;
			}
		}

	}

	return 0;
}
