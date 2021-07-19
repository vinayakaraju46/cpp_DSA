#include<bits/stdc++.h>

using namespace std;



int main() {
    map<string,int> dict;
    map<string,int>::iterator itr1;

    string sentence, tmp;
    getline(cin, sentence);
    stringstream str_strm(sentence);
    vector<string> words;
    vector<string>::iterator itr;
    string banned;
    cout << "Banned Word" << endl;
    cin >> banned;
    char delim = ' ';
    while(getline(str_strm, tmp, delim)) {
        words.push_back(tmp);
        itr1 = dict.find(tmp);
        if(tmp == itr1->first) {
            itr1->second += 1;
        }else if(dict.find(tmp) == dict.end()) {
            dict.insert(pair<string, int>(tmp, 1));
        }
    }
    cout << endl;
    for(int i=0; i<words.size(); i++) {
        cout << words[i] << endl;
    }

    for(itr1=dict.begin(); itr1!=dict.end(); itr1++) {
        cout << "First :" << itr1->first << " second: "<< itr1->second << endl;
    }
    transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);
    cout << tmp << endl;
    cout << dict.begin()->first << endl;

    return 0;
}