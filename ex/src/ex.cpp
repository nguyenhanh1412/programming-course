#include <iostream>
#include <string>
#include <fstream>  // (1)

using namespace std;

int main()
{
	fstream myText;                    // (2)
	myText.open("D:/eclipse-workspace/ex/myText.gitignore"); // (2)

	string data;
	string line;// (3)
	while(!myText.eof()){
		getline(myText, line);
		data += line;
	}
	            // (3)

	myText.close();                    // (4)

	cout << data << endl;
}
