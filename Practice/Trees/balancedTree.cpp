#include <iostream>
using namespace std;

int height(Node * root,bool & valid){
        if(root == nullptr){
            return 0;
        }
        
        int L=height(root->left,valid);
        int R =height(root->right,valid);
        if(abs(L-R)>1){
            valid = 0;
        }
        return 1 + max(L,R);
        
    }
    bool isBalanced(Node* root) {
        bool valid = 1;
       height(root,valid);
        return valid;
    }