#include <iostream>
#include <string>
#include <fstream>  // (1)

using namespace std;

int main()
{
	int arr[100];
	int n;
	cout <<"so luong hoa:";
	cin >> n;
	cout<<"thu tu hoa";
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	int c, c_max;
	c = 1;
	c_max = 0;
	for(int i = 0; i < n; i++){
		if(arr[i] == arr[i+1]){
			c++;
		}
	}
	cout<<"nnn";
	c_max = c;
	cout << c_max;


}

