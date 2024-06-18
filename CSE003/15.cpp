// Intersection of Linked Lists

#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void insertAtHead(Node* &head, int d){
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}

class Solution {
public:
    Node* removeNthFromEnd(Node* head, int n) {
        Node* dummy = new Node(0);
        dummy->next = head;
        Node* first = dummy;
        Node* second = dummy;

        for (int i = 0; i <= n; ++i) {
            first = first->next;
        }

        while (first != nullptr) {
            first = first->next;
            second = second->next;
        }

        Node* temp = second->next;
        second->next = second->next->next;
        delete temp;

        return dummy->next;
    }
};


int main(){
    Node* node1 = new Node(10);
    Node* head = node1;
    // insertAtTail(head,12);
    insertAtHead(head,16);
    // print(head); 
}
