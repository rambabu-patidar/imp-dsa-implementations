#include<bits/stdc++.h>
using namespace std;

// This will work only for lowercase alphabets 

class TrieNode {
    public:
    vector<TrieNode*> childrens;
    bool isWord;

    // constructor
    TrieNode() : childrens(26, nullptr), isWord(false){};

    // same as above constructor
    
    // TrieNode() {
    //     this->childrens = vector<TrieNode*>(26, nullptr);
    //     this->isWord = false;
    // }

    ~TrieNode() {
        for (TrieNode* child: childrens) {
            delete child;
        }
    }
};

class Trie {
    private: 
    TrieNode *root;

    public:

    Trie() {
        root = new TrieNode();
    }

    ~Trie() {
        delete root;
    }

    void insert(string);
    bool search(string);
    bool startsWith(string);
};


void Trie::insert(string word) {
    // create a temp node so you don't loose reference of root
    TrieNode *node = root;
    
    for (char letter: word) {
        // resolve the letter to indexx
        int idx = letter - 'a';
        if (node->childrens[idx] == nullptr) { // this mean the letter is not yet included in trie
            node->childrens[idx] = new TrieNode();
        }
        node = node->childrens[idx];
    }
    node->isWord = true; // specifies that this is a word ending here.
    return;
}

bool Trie::search(string word) {
    TrieNode *node = root;

    for (char letter: word) {
        int idx = letter - 'a';

        if (node->childrens[idx] == nullptr) {
            return false;
        }
        node = node->childrens[idx];
    }
    return node->isWord;
}

bool Trie::startsWith(string word) {
    TrieNode *node = root;

    for (char letter : word)
    {
        int idx = letter - 'a';

        if (node->childrens[idx] == nullptr)
        {
            return false;
        }
        node = node->childrens[idx];
    }
    return true;
}

int main(){

    Trie trie;
    trie.insert("rambabu");
    trie.insert("ramkumar");

    cout << trie.search("rambabu") << endl; // return true
    cout << trie.startsWith("ram") << endl; // return true

    return 0;
}