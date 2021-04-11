//============================================================================
// Name        : Lab_5.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm> //std::sort
#include <stdlib.h> //std::rand
#include <cmath> //std::floor
using namespace std;

int binSearch(int num, vector<int> numArr){
	int l = 0;
	int r = numArr.size() - 1;
	while(l <= r){
		int mid = floor((l+r)/2);
		if (numArr[mid] < num)
			l = mid + 1;
		else if (numArr[mid] > num)
			r =  mid -1;
		else
			return mid;
	}
	return -1;
}


int main() {
	int num;
	cout << "Enter a number: " << endl;
	cin >> num;
	vector<int>numArr(100);
	for(int i=0; i<100; i++){
		numArr[i] = rand() %100; // numArr in the range 0 to 99
	}
	sort (numArr.begin(), numArr.end());
	for (int i=0; i<100; i++){
		cout << numArr[i] <<" ";
	}
	cout << endl;
	int x =  binSearch(num, numArr);
	if(x==-1)
		cout << "Not found";
	else
		cout << "Found";


	return 0;
}
