/*#include <iostream>
#include <vector>
using namespace std;

int main()
{
	cout << "Enter vector length\n";
	int n;
	cout << "n = ";
	cin >> n; //
	vector<int> a;// Создаем пустой вектор

	float temp; // временная переменная

	cout << "\nEnter vector values:\n";
	for (int i = 0; i < n; i++){
		cin >> temp;
		if (temp != int(temp)) {		//изменение типа переменной
			printf("Error");
			return 0;		//остановлена программа
		}
		a.push_back(int(temp));//вставлять элементы в вектор сзади. ( push elements into a vector from the back.)
	}
	cout << "\nSorting.....\n"; // Сортировка по алгоритму пузырька (сравнение каждой пары и обмен их местами)
	for(int i = 0; i < n-1; i++){
		for (int j = i +1; j < n; j++){
	    	if(a[i] < a[j]){
	    		temp = a[i];
	   		    a[i] = a[j];
	   		    a[j] = temp;
	   		 }
	   	}
   }

	cout << "\nPrinting vector number according the rule:\n";
	cout << "if the value is odd, then print with @\n";
	cout << "if the value is even, then print with !\n";
	for (int i= 0; i < n; i++){
		if((int)a[i] % 2== 0){
			cout << a[i] << "! ";
	    }
	    else {
	    	cout << a[i] << "@ ";
	    }
	}

	return 0;
}*/
//=================================================
/*#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

vector<int> Sortirovka(vector<int>& v){
	sort(begin(v), end(v));
	return v;
}
int main(){
	vector <int> nums = {3, 1,5,2,2,0,1};
	nums = Sortirovka(nums);
	//sort(begin(nums),end(nums));
	for (auto i : nums){
		cout << i <<" ";
	}
	return 0;
}*/
//====================================================
/*#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

void Print(vector <bool>& a){
	for (auto p :a){
		cout<<p<<" ";
	}
}

int main(){
	vector <bool> drink(28, false);
	drink[22] = true;
	Print(drink);
	cout<<endl;
	drink.push_back(true);
	Print(drink);
	cout << endl;
	drink.resize(31,true);
	Print(drink);
	cout<<endl;
	drink.assign(10,true);
	Print(drink);
	return 0;
}*/
//=========================================
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

void Print(map <int, string>& a){
	for (auto p:a){
		cout << p.first << "===== " << p.second << endl;
	}
}

int main (){
	map <int, string> olimp;
	olimp[2021] = "Tokiyo";
	olimp[1980] = "Moscow";
	olimp[2014] = "Sochi";
	Print(olimp);

	return 0;

}




