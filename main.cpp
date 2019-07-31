#include <bits/stdc++.h>
#include "TrieNode.h"
using namespace std;

int main() {
    int choice;
    cin >> choice;
    Trie t;
    
    
    while(choice != -1){
        string word;
        bool ans;
        switch(choice) {
            case 1 : 
                cin >> word;
                t.insertWord(word);
                break;
            case 2 : 
                cin >> word;
                ans = t.search(word);
                if (ans) {
                    cout << "true" << endl;
                } else {
                    cout << "false" << endl;
                }
                break;
            case 3:
                cin >> word;
                t.autoComplete(word);
                break;
            default :
                return 0;
        }
        cin >> choice;
    }
    return 0;
}