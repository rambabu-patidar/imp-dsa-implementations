#include<bits/stdc++.h>
using namespace std;

// can be traversed only in forward direction.

class ListNode {
    public:

    ListNode *next;
    int val;

    ListNode(): next(nullptr) {};

    ListNode(int val): next(nullptr) {
        this->val = val;
    }

    ListNode(int val, ListNode *next) {
        this->next = next;
        this->val = val;
    }
};

class List {
    private: 
    ListNode *head;
    // here you can have a length variable so as to get length in constant time complexity.

    public:
    List() {
        head = nullptr;
    }

    void insert(int, int); // insert at specified index and if index < 0 insert at head or if index > length insert at the tail of list
    void insertAtHead(int);
    void insertAtTail(int);

    void printList();

    bool search(int); // searches a given value

    // functions you can implement 
    void reverse();
    int lengthOfList();
    void deleteNode();
    void deleteByIndex();

};

void List::insert(int val, int index) {
    if (index < 0) {
        insertAtHead(val);
        return;
    }

    ListNode *node = head;

    while (index != 0 && node != nullptr){ 
        node = node->next;
        index--;
    }

    if (index > 0) {
        insertAtTail(val);
        return;
    }

    ListNode *newNode = new ListNode(val);
    newNode->next = node->next;
    node->next = newNode;
    return;

}

void List::insertAtHead(int val) {
    // In this case the head of list changes
    ListNode *newHead = new ListNode(val);
    newHead->next = head;
    head = newHead;
    return;
}

void List::insertAtTail(int val) {

    if (head == nullptr) {
        insertAtHead(val);
        return;
    }

    ListNode *node = head; // temp node 

    while (node->next != nullptr) {
        node = node->next;
    }

    // create a new node with given value
    ListNode *newNode = new ListNode(val);

    // insert at end
    node->next = newNode;
    return;
}

void List::printList() {
    ListNode *node = head;

    while (node != nullptr) {
        cout << node->val << "->";
        node = node->next;
    }
    cout << "NULL" << endl;
    return;
}

bool List::search(int val) {
    ListNode *node = head;
    while (node != nullptr) {
        if (node->val == val) {
            return true;
        }
        node = node->next;
    }
    return false;
}

int main(){

    List list;

    vector<int> nums = {1, 2, 3, 4, 5, 6};
    for (int num: nums) {
        list.insertAtTail(num);
    }

    list.printList();
    
    return 0;
}