// Linked List

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

int main(){
    Node* node1 = new Node(10);
    Node* head = node1;
    // insertAtTail(head,12);
    insertAtHead(head,16);
    // print(head); 
}