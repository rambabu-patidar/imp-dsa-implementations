#include<bits/stdc++.h>
using namespace std;

// This can be used for any types of character.
// ans occupies only the required space

class TrieNode {
    public:
    unordered_map<char, TrieNode*> childrens; // you can use map also but order is useless here.
    bool isWord;

    TrieNode() : isWord(false){
        this->childrens = unordered_map<char, TrieNode*>();
        this->isWord = false;
    };

};

class Trie {
    private: 
    TrieNode *root;

    public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* node = root;
        for (char letter: word) {
            if (node->childrens.find(letter) == node->childrens.end()) {
                node->childrens[letter] = new TrieNode();
            }
            node = node->childrens[letter];
        }
        node->isWord = true;
    }

    bool search(string word) {
        TrieNode *node = root;
        for(char letter: word) {
            if (node->childrens.find(letter) == node->childrens.end()) {
                return false;
            }
            node = node->childrens[letter];
        }
        return node->isWord;
    }

    bool startsWith(string word) {
         TrieNode *node = root;
        for(char letter: word) {
            if (node->childrens.find(letter) == node->childrens.end()) {
                return false;
            }
            node = node->childrens[letter];
        }
        return true;
    }
};

int main(){

    Trie trie;
    trie.insert("Rambabu_Patidar");
    trie.insert("Rambabu_");
    trie.insert("rambabu_patidar");
    trie.insert("%$ram$%*patidar");

    cout << trie.search("%$ram$") << endl;
    cout << trie.startsWith("%$ram$") << endl;
    cout << trie.startsWith("rambabu_pati");


    return 0;
}