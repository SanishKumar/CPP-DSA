#include <iostream>
#include <queue>

using namespace std;

int main()
{
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node * n->q.front();
        q.pop();
        cout << n->data;
        if (n->left != NULL)
        {
            q.push(n->left);
        }
        if (n->right != NULL)
        {
            q.push(n->right);
        }
    }
}