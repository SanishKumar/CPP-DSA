
#include <iostream>
#include <algorithm>
using namespace std;

/* The Node structure is
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
    public:
      /*You are required to complete this method*/
      int minDepth(Node *root) {
          // Your code here
          if(root == NULL) return 0;
          
          if(root -> left == NULL) return 1 + minDepth(root->right);
          if(root -> right == NULL) return 1 + minDepth(root->left);
          
          return 1 + min(minDepth(root->left), minDepth(root->right));
      }
};

int main() {
    // Creating a sample tree:
    //         1
    //        / \
    //       2   3
    //      /
    //     4
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);

    Solution sol;
    cout << "Minimum Depth of the Tree: " << sol.minDepth(root) << endl;

    return 0;
}