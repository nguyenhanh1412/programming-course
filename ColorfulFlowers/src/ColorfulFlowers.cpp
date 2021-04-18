#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;


int main(){
	vector <int> arr;
	arr.push_back(1105);
	arr.push_back(1729);
	arr.push_back(2567);
	arr.push_back(2579);
	arr.push_back(2587);
	arr.push_back(2593);
	arr.push_back(2903);
	arr.push_back(2911);
	arr.push_back(2921);
	arr.push_back(2939);
	arr.push_back(3089);
	arr.push_back(3103);
	arr.push_back(3113);
	arr.push_back(3121);
	arr.push_back(6601);

	vector <int> arr_a;
	arr_a.push_back(2);
	arr_a.push_back(3);
	arr_a.push_back(5);
	arr_a.push_back(7);
	arr_a.push_back(9);
	arr_a.push_back(11);
	arr_a.push_back(13);
	arr_a.push_back(17);
	arr_a.push_back(19);
	arr_a.push_back(23);
	arr_a.push_back(29);
	arr_a.push_back(31);
	for(int i = 0; i < (long)arr.size(); i++){
		for(int j = 0; j < (long)arr_a.size(); j++){
			if(__gcd(arr[i], arr_a[j]) == 1){
				cout << "GCD ( " << arr[i] << ", " << arr_a[j] << ") = 1" << endl;
				}
			}
		cout <<endl <<endl;;
	}


	return 0;
}
