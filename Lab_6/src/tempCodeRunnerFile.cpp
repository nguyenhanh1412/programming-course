void swapKeyVal(string key, vector<Word>& dict) {
	string temp;
	for (int i = 0; i < (int)dict.size(); i++) {
		if (key.compare(dict[i].key) == 0) {
			temp = dict[i].val;
			dict[i].key = temp;
			dict[i].val = key;
			//break;
		}
	}
}