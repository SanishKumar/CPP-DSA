#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;

        Node(int data){
            this->data = data;
            this->next = NULL;
        }

        ~Node(){
            int value = this -> data;
            if(this->next != NULL){
                delete next;
                this->next = NULL;
            }
            cout << "Memory freed for node with data " << value << endl;
        }
};

void insertAtHead(Node* &head, int d){

    Node* temp = new Node(d);
    temp->next = head;
    head = temp;

}

void insertAtTail(Node* &tail, int d){
    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

void deleteNode(int position, Node* &head){

}

void display(Node* &head){
    Node* temp = head;

    while(temp!=NULL){
        cout<<temp->data <<" ";
        temp = temp->next;
    }
    cout << endl;
}

int main(){
    Node* node1 = new Node(10);

    Node* head = node1;
    Node* tail = node1;
    display(head);

    insertAtHead(head, 12);
    display(head);

    insertAtTail(tail, 15);
    display(head);
}