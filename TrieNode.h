#include <bits/stdc++.h>
using namespace std;
class TrieNode {
	public :
	char data;
	TrieNode **children;
	bool isTerminal;

	TrieNode(char data) {
		this -> data = data;
		children = new TrieNode*[26];
		for(int i = 0; i < 26; i++) {
			children[i] = NULL;
		}
		isTerminal = false;
	}
};
class Trie {
    TrieNode *root;
    
    public :
    
    Trie() {
        root = new TrieNode('\0');
    }
    
    void insertWord(TrieNode *root, string word) {
        if(word.size() == 0) {
            root -> isTerminal = true;
            return;
        }
        
        int index = word[0] - 'a';
        TrieNode *child;
        if(root -> children[index] != NULL) {
            child = root -> children[index];
        }
        else {
            child = new TrieNode(word[0]);
            root -> children[index] = child;
        }
        
        insertWord(child, word.substr(1));
    }
    
    void insertWord(string word) {
        insertWord(root, word);
    }
    
    bool searchWord(string word, TrieNode *root) {
      if(word.size() == 0)
        return root -> isTerminal;
      
      bool k;
      
      int index = word[0] - 'a';
      if(root -> children[index] != NULL)
        k = searchWord(word.substr(1), root -> children[index]);
      else return false;
      return k;
    }
     
    bool search(string word) {
        return searchWord(word, root); 
    }

    void allPaths(TrieNode *node, string output) {
        if(node -> isTerminal) {
            cout << output << endl;
        }
        for(int i = 0;i<26;i++) {
            if(node -> children[i] != NULL) {
                char c = 'a' + i;
                allPaths(node -> children[i], output + c);
            }
        }
    }
    
    TrieNode *findRoot(TrieNode *root, string word) {
        if(word.size() == 0) {
            return root;
        }
        int index = word[0] - 'a';
        TrieNode *child = root -> children[index];
        if(child == NULL) {
            return NULL;
        }
        return findRoot(child, word.substr(1));
    }

    void autoComplete(string word) {
        TrieNode *node = findRoot(root, word);
        if(node == NULL) {
            return ;
        }
        string output = word + "";
        allPaths(node, output);
    }
  
};

