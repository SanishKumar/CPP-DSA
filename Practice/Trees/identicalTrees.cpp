

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val) : data(val), left(NULL), right(NULL) {}
};

Node *createTree()
{
    int data;
    cout << "Enter data (-1 for NULL): ";
    cin >> data;

    if (data == -1)
        return NULL;

    Node *root = new Node(data);
    cout << "Enter left child of " << data << ": ";
    root->left = createTree();
    cout << "Enter right child of " << data << ": ";
    root->right = createTree();

    return root;
}

bool isIdentical(Node *r1, Node *r2)
{
    if (r1 == NULL && r2 == NULL)
        return true;
    if ((r1 == NULL && r2 != NULL) || (r1 != NULL && r2 == NULL))
        return false;
    if (r1->data != r2->data)
        return false;

    return isIdentical(r1->left, r2->left) && isIdentical(r1->right, r2->right);
}

int main()
{
    cout << "Create first tree:" << endl;
    Node *root1 = createTree();

    cout << "Create second tree:" << endl;
    Node *root2 = createTree();

    if (isIdentical(root1, root2))
    {
        cout << "The trees are identical." << endl;
    }
    else
    {
        cout << "The trees are not identical." << endl;
    }

    return 0;
}