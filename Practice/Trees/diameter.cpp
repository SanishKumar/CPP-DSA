#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

int fun(Node *root, int *height)
{

    if (root == NULL)
        return 0;

    int left = fun(root->left, height);
    int right = fun(root->right, height);

    int dai = left + right;

    if (dai > *height)
        *height = dai;

    return max(left, right) + 1;
}
// Function to return the diameter of a Binary Tree.
int diameter(Node *root)
{

    int height = 0;
    fun(root, &height);

    return height;
}

int main()
{
    // Creating a sample binary tree
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // Calculating the diameter of the binary tree
    cout << "Diameter of the binary tree: " << diameter(root) << endl;

    // Freeing allocated memory
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root;

    return 0;
}
