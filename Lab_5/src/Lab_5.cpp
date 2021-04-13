//============================================================================
// Name        : Lab_5.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binSearch(vector<int> numArr, int num, int l, int r){
    if(r >=l ){
        int mid = l + (r - l) / 2;

        if(numArr[mid] == num)
        	return mid;

        if (numArr[mid] > num)
        	return binSearch(numArr, num, l, mid - 1);

        return binSearch(numArr, num, mid + 1, r);
    }

    return -1;
}


vector<int> indexSearch(vector<int> numArr, int num, int l, int r){
	vector<int> indexArr;
	int x = binSearch(numArr, num, l, r);
	if (x == -1)
	{
		indexArr.push_back(x);
		return indexArr;
	}
	else {
		int i = 0;
		while(numArr[x - i] == num){
			indexArr.push_back(x-i);
			i++;
		}

		i = 1;
		while(numArr[x + i] == num){
			indexArr.push_back(x+i);
			i++;
		}
		sort(indexArr.begin(), indexArr.end());
		return indexArr;
	}
}


int main(){
	cout << "Array of numbers: ";
	vector<int> numArr(100);
	for(int i=0; i<100; i++){
		numArr[i] = rand() %100; // numArr in the range 0 to 99
	}
	sort (numArr.begin(), numArr.end());
	for (int i=0; i<100; i++){
		cout << numArr[i] <<" ";
	}
	cout << endl;

	int num;
	cout << "Enter a number: ";
	cin >> num;

	int n = numArr.size();

	vector<int> indexArr = indexSearch(numArr,num, 0, n-1);
	cout << "Index Array: [ ";
	for (int i = 0; i < (int)indexArr.size(); i++){
		cout << indexArr.at(i) << " ";
	}
	cout << "]";
    return 0;
}
