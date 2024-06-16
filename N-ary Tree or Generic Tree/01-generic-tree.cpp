#include<bits/stdc++.h>
using namespace std;

// This type of tree variable number of children at each level 
// and we don't know the exact childrens prior.

class NaryTreeNode {
    public:
    vector<NaryTreeNode*> childrens;
    int val;

    NaryTreeNode() {
        this->childrens = vector<NaryTreeNode*>();
    }

    NaryTreeNode(int val) {
        this->val = val;
        this->childrens = vector<NaryTreeNode*>();
    }
};

class NaryTree {
    private: 
    NaryTreeNode *root;

    public:
    NaryTree () {
        root = nullptr;
    }

    void buildTreeFromPreorder(vector<int> preorder, vector<int> childCounts);
    void printPreorder();

    private: 
    NaryTreeNode *buildTreeFromPreorderUtil(vector<int>, vector<int>, int&, int&);
    void printPreorderUtil(NaryTreeNode* root);
};

NaryTreeNode *NaryTree::buildTreeFromPreorderUtil(vector<int> preorder, vector<int> childCounts, int &idx, int &childIdx) {
    if (idx >= preorder.size()) {
        return nullptr;
    }

    NaryTreeNode *node = new NaryTreeNode(preorder[idx]);
    int childCount = childCounts[childIdx++];

    for (int i = 0; i < childCount; i++) {
        node->childrens.push_back(buildTreeFromPreorderUtil(preorder, childCounts, ++idx, childIdx));
    }
    return node;
}

void NaryTree::buildTreeFromPreorder(vector<int> preorder, vector<int> childCounts) {
    int idx = 0;
    int childIdx = 0; 

    root = buildTreeFromPreorderUtil(preorder, childCounts, idx, childIdx);
}

void NaryTree::printPreorderUtil(NaryTreeNode *root) {
    if (!root) {
        return;
    }

    cout << root->val << " ";

    for (NaryTreeNode *childs: root->childrens) {
        printPreorderUtil(childs);
    }
}

void NaryTree::printPreorder() {
    printPreorderUtil(root);
}

int main(){

    NaryTree tree;

    vector<int> preorder = {1, 2, 3, 5, 6, 4};    // Preorder traversal
    vector<int> childCounts = {3, 0, 2, 0, 0, 0}; // Number of children for each node in preorder traversal

    tree.buildTreeFromPreorder(preorder, childCounts);
    tree.printPreorder();
    return 0;
}