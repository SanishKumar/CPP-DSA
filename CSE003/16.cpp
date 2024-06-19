#include <iostream>
// #define 5 1000 
using namespace std;

class Stack {
    int top;

public:
    int arr[5]; 

    Stack() {
        top = -1; 
    }

    bool push(int x);
    int pop();
    int peek();
    bool isEmpty();
};

bool Stack::push(int x) {
    if (top >= (5 - 1)) {
        cout << "Stack Overflow";
        return false;
    } else {
        arr[++top] = x;
        cout << x << " pushed into stack\n";
        return true;
    }
}

int Stack::pop() {
    if (top < 0) {
        cout << "Stack Underflow";
        return 0;
    } else {
        int x = arr[top--];
        return x;
    }
}

int Stack::peek() {
    if (top < 0) {
        cout << "Stack is Empty";
        return 0;
    } else {
        int x = arr[top];
        return x;
    }
}

bool Stack::isEmpty() {
    return (top < 0);
}

int main() {
    Stack s;
    s.push(50);
    s.push(60);
    s.push(250);
    cout << "Elements present in stack: ";
    while (!s.isEmpty()) {
        cout << s.peek() << " ";
        s.pop();
    }

    cout << s.pop() << " Popped from stack\n";
    cout << "Top element is " << s.peek() << endl;
    cout << "Elements present in stack: ";
    while (!s.isEmpty()) {
        cout << s.peek() << " ";
        s.pop();
    }
    return 0;
}
