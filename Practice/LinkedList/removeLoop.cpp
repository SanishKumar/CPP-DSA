/*************************************************

    class Node {
        public :

        int data;
        Node *next;

        Node(int data) {
            this -> data = data;
            this -> next = NULL;
        }
    };

*************************************************/

#include<iostream>
using namespace std;

class Node{
    
}

Node *getIntersection(Node *head) {
  if (head == NULL)
    return NULL;
  Node *slow = head;
  Node *fast = head;

  while (slow != NULL && fast != NULL) {
    fast = fast->next;
    if (fast != NULL) {
      fast = fast->next;
    }
    slow = slow->next;
    if (slow == fast) {
      return slow;
    }
  }
  return NULL;
}

Node *getNode(Node *head) {

  if (head == NULL) {
    return NULL;
  }

  Node *slow = head;
  Node *intersection = getIntersection(head);

  if (intersection == NULL)
    return NULL;

  while (slow != intersection) {
    slow = slow->next;
    intersection = intersection->next;
  }
  return slow;
}

Node *removeLoop(Node *head) {

  if (head == NULL) {
    return NULL;
  }

  Node *startingLoop = getNode(head);

  if (startingLoop == NULL)
    return head;

  Node *temp = startingLoop;

  while (temp->next != startingLoop) {
    temp = temp->next;
  }

  temp->next = NULL;

  return head;
}