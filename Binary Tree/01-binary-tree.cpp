#include<bits/stdc++.h>
using namespace std;

// All types of binary trees can be repersented using this structure.

class TreeNode {
    public: 
    TreeNode *left;
    TreeNode *right;
    int val;

    TreeNode(): left(nullptr), right(nullptr) {}
    TreeNode(int val): left(nullptr), right(nullptr) {
        this->val = val;
    }

    TreeNode(int val, TreeNode *left, TreeNode* right) {
        this->val = val;
        this->left = left;
        this->right = right;
    }
};

class Tree {
    private:
    TreeNode *root;

    public:

    Tree() {
        root = nullptr;
    }

    ~Tree() {
        delete root;
    }

    void buildTreeFromPreorder(vector<int>);
    void printPreorder();
    friend void printPreorderUtil(TreeNode* root);

    // many more function you can implement but here we are focusing on implementations.
};



TreeNode *buildTreeFromPreorderUtil(vector<int> preorder) {
    static int idx = 0;

    if ( idx >= preorder.size() || preorder[idx] == -1) {
        idx++;
        return nullptr;
    }
    TreeNode *node = new TreeNode(preorder[idx++]);

    node->left = buildTreeFromPreorderUtil(preorder);
    node->right = buildTreeFromPreorderUtil(preorder);

    return node;
}


void Tree::buildTreeFromPreorder(vector<int> preorder) {
    root = buildTreeFromPreorderUtil(preorder);
}

void printPreorderUtil(TreeNode *root) {

    if (root == nullptr) {
        return;
    }
    cout << root->val << " ";

    printPreorderUtil(root->left);
    printPreorderUtil(root->right);
}

void Tree::printPreorder() {
    printPreorderUtil(root);
}

int main(){

    Tree tree;

    vector<int> preorder = {1, 2, 3, -1, -1, -1, 4, 5, 6, -1, -1, -1, 7, -1, -1};

    tree.buildTreeFromPreorder(preorder);
    tree.printPreorder();
    return 0;
}

/* since I don't want the root to be present in the main function I made it private 
and now to print the tree we need to pass the root in original function,
and because of this problem we can't use that version of print function that accept tree as parameter.
hence I created a util function for printing but that util too needs the root parameter to print tree.

so I recalled the concept of friend function, which can use the private member of a class and its declaration is
similar to all other function we define in normal c++ without classes. hence we initialized the funciton in class
and made it friend of that class now it can access private member root and we don't need to pass the root in main function.*/