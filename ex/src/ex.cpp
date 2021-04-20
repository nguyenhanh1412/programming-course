#include<iostream>
#include<vector>
#include<string>
#include<fstream>
using namespace std;

// write vector v to text.txt
void write(vector<string> v){
	ofstream file;
	file.open("text.txt");
	for(int i=0;i<v.size();++i){
		file<<v[i]<<endl;
	}
	file.close();
}

// read data from from text.txt and store it in vector v
void read(vector<string> &v){
	ifstream file;
	file.open("text.txt");
	string line;
	while(getline(file, line)){
		v.push_back(line);
	}
	file.close();
}

int main()
{
	vector<string> v  = {"My", "name", "is", "Hong", "Hanh"};
	cout<<"Vector: ";
	for(int i=0;i<v.size();++i)
		cout<<v[i]<<" ";
	cout<<endl;

	//  writing v to file "text.txt"
	write(v);

	/*vector<string> temp;
	// reading vector from "text.txt" and storing data in temp
	read(temp);
	cout<<"Vector After Reading from File: ";
	for(int i=0;i<temp.size();++i)
		cout<<temp[i]<<" ";
	cout<<endl;*/

}
