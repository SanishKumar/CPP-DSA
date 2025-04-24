#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

int height(Node *root, bool &valid)
{
    if (root == nullptr)
    {
        return 0;
    }

    int L = height(root->left, valid);
    int R = height(root->right, valid);
    if (abs(L - R) > 1)
    {
        valid = 0;
    }
    return 1 + max(L, R);
}
bool isBalanced(Node *root)
{
    bool valid = 1;
    height(root, valid);
    return valid;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    if (isBalanced(root))
    {
        cout << "The tree is balanced." << endl;
    }
    else
    {
        cout << "The tree is not balanced." << endl;
    }

    return 0;
}