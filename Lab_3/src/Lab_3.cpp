#include <iostream>
#include <string.h>

using namespace std;

int countSubStr(string s);
int compareToPreSub(string subStr, string s);

int countSubStr(string s) {
	// Calculate number of substrings, which are equal to prefix or subfix
	int count = 0;
	for (int i=0; i < (int)s.size(); i++) {
		for (int j=1; j <= (int)s.size()-i; j++) {
			string subStr = s.substr(i, j);
			count += compareToPreSub(subStr, s);
		}
	}
	return count;
}

int compareToPreSub(string subStr, string s) {
	// Compare a substring to prefix and suffix of a string
	int num = 0;
	string prefix = s.substr(0, subStr.size());
	string subfix = s.substr(s.size()-subStr.size(), subStr.size());
	if (subStr.compare(prefix) == 0 && subStr.compare(subfix) == 0) {
		num = 0;
	}
	else if (subStr.compare(prefix) == 0 || subStr.compare(subfix) == 0) {
		num = 1;
	}
	return num;
}

int main(){
	int n;
	cin >> n;
	string s[n];
	for (int i=0; i<n; i++) {
		cin >> s[i];
	}
	for (int i=0; i<n; i++) {
		cout << countSubStr(s[i]) << endl;
	}

	return 0;
}
