void printDict(vector<Word>& dict) {
    for (int i = 0; i < (int)dict.size(); i++){
        cout << dict[i].key<< " => ";
        for(int j = 0; j < (int)dict[i].val.size(); j++){
             cout << dict[i].val[j] << endl;
        }
    }   
    cout << endl;
}