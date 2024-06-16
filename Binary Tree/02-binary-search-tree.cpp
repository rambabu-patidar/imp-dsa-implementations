#include<bits/stdc++.h>
using namespace std;

class TreeNode {
    public: 
    TreeNode *left;
    TreeNode *right;
    int val;

    TreeNode(): left(nullptr), right(nullptr), val(0){};
    
    TreeNode(int val): left(nullptr), right(nullptr) {
        this->val = val;
    }

    TreeNode(int val, TreeNode *left, TreeNode *right) {
        this->left = left;
        this->right = right;
        this->val = val;
    }
};


class BST {
    private: 
    TreeNode *root;

    public:

    BST(){
        this->root = nullptr;
    }

    void insert(int val);
    bool search(int val);
    void deleteInBST(int val);
    void printInorder();

    private: 
    //  utility functions
    TreeNode *insertUtil(int val, TreeNode *&root);
    bool searchUtil(int target, TreeNode * root);
    TreeNode *deleteInBSTUtil(int toDelete, TreeNode*& root);
    TreeNode *minValueNode(TreeNode* root);
    void printInorderUtil(TreeNode* root);
};

TreeNode* BST::insertUtil(int val, TreeNode* &root) {
    if (root == nullptr) {
        return new TreeNode(val);
    }

    if (root->val > val) {
        root->left = insertUtil(val, root->left);
    }else {
        root->right = insertUtil(val, root->right);
    }

    return root;
    
}

void BST::insert(int val) {
    root = insertUtil(val, root);
}

bool BST::searchUtil(int target, TreeNode* root) {
    if (root == nullptr) {
        return false;
    }

    if (root->val == target) {
        return true;
    }

    if (root->val > target) {
        return searchUtil(target, root->left);
    }
    return searchUtil(target, root->right);
}

bool BST::search(int target) {
   return searchUtil(target, root);
}

TreeNode* BST::minValueNode(TreeNode *root) {
    TreeNode * node = root;

    while (node && node->left != nullptr){
        node = node->left;
    }

    return node;
}

TreeNode* BST::deleteInBSTUtil(int toDelete, TreeNode *& root) {
    if (root == nullptr) {
        return root;
    }

    // check if it is in left subtree
    if (root->val > toDelete) {
        root->left = deleteInBSTUtil(toDelete, root->left);
    } else if (root-> val < toDelete) { // check in right subtree
        root->right = deleteInBSTUtil(toDelete, root->right);
    } else { // current node is the node to delete.

        // it is has only one child or
        // it has no child
        if (root->left == nullptr) {
            TreeNode *temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }

        // if it reaches here means node to delete has both child present.
        // find the inorder successor(which is smallest element in the right subtree of toDelete node)
        // and replace it with toDelete node and delete the swapped node;

        TreeNode *inorderSuccessor = minValueNode(root->right);

        root->val = inorderSuccessor->val;

        root->right = deleteInBSTUtil(inorderSuccessor->val, root->right);
    }
    return root;
}

void BST::deleteInBST(int toDelete) {
    root = deleteInBSTUtil(toDelete, root);
}

void BST::printInorderUtil(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    printInorderUtil(root->left);
    cout << root->val << " ";
    printInorderUtil(root->right);
}

void BST::printInorder() {
    printInorderUtil(root);
    return;
}


int main(){

    BST bst;

    bst.insert(10);
    bst.insert(20);
    bst.insert(5);
    bst.insert(15);

    bst.printInorder();

    cout << endl << bst.search(10) << endl;

    bst.deleteInBST(10);

    bst.printInorder();

    return 0;
}