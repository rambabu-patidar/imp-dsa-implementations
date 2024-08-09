#include<bits/stdc++.h>
using namespace std;

// the core idea is that insert the element as you would do it in BST
// but now check if the insertion caused the imbalance if it has then rebalance it 

// the same is for the deletion that if the deletion of any node imbalance the tree
// we need to rebalance it 

// hence the tree is called self balancing.

class TreeNode {
    public:
    int val;
    TreeNode* left;
    TreeNode* right;


    TreeNode(int val) {
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }

    int getValue(TreeNode* node) {
        return node->val;
    }  
};

class BST{
    public:
    TreeNode* root;

    private:

    TreeNode* rightRotate(TreeNode* p) {
        TreeNode* c = p->left;
        TreeNode* t = c->right;

        c->right = p;
        p->left = t;
        return c;
    }

    TreeNode* leftRotate(TreeNode* c) {
        TreeNode* p = c->right;
        TreeNode* t = p->left;

        p->left = c;
        c->right = t;
        return p;
    }

    TreeNode* rotate(TreeNode* root) {
        // left heavy
        if (getHeight(root->left) - getHeight(root->right) > 1) {
            // left left case
            if (getHeight(root->left->left) > getHeight(root->left->right)) {
                return rightRotate(root);
            }
            // left right case
            if (getHeight(root->left->left) < getHeight(root->left->right)) {
                root->left = leftRotate(root->left);
                return rightRotate(root);
            }
        }
        // right Heavy
        if (getHeight(root->left) - getHeight(root->right) < -1) {
            // right right case
            if (getHeight(root->right->right) > getHeight(root->right->left)) {
                return leftRotate(root);
            }
            // right left case
            if (getHeight(root->right->right) < getHeight(root->right->left)) {
                root->right = rightRotate(root->right);
                return leftRotate(root);
            }
        }

        return root;
    }

    int getHeight(TreeNode* node) {
        if (node == nullptr) {
            return -1;
        }

        if (node->left == nullptr && node->right == nullptr) {
            return 0;
        }

        return max(getHeight(node->left), getHeight(node->right)) + 1;
    }
    
    TreeNode* insertUtil(TreeNode* root, int val) {
        if (root == nullptr) {
            root = new TreeNode(val);
            return root;
        }

        if (val < root->val) {
            root->left = insertUtil(root->left, val);
        } else if (val > root->val) {
            root->right = insertUtil(root->right, val);
        }

        root = rotate(root); // restructure the tree if something it got disbalanced
        return root;
    }

    void printBSTUtil(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        printBSTUtil(root->left);
        printBSTUtil(root->right);
    }
    
    public:

    BST() {
        this->root = nullptr;
    }
    
    void insert(int val) {
        this->root = insertUtil(this->root, val);
    }

    void printBST() {
        printBSTUtil(this->root);
    }

    void printHeight() {
        cout << getHeight(this->root);
        return;
    }

};

int main(){

    BST myTree;

    for (int i = 1; i <= 1000; i++) {
        myTree.insert(i);
    }
    // myTree.printBST();
    myTree.printHeight();
    return 0;
}