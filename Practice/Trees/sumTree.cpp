class Solution {
    
    int isSum(Node* root)
    {
        if (root == NULL) 
        {
            return 0;
        }

        if(root->left==NULL && root->right==NULL)
        {
            return root->data;
        }
        
        int left = isSum(root->left);
        if(left == -1)
        {
            return -1;
        }
        
        int right = isSum(root->right);
        if(right == -1)
        {
            return -1;
        }
        
        if(left + right != root->data )
        {
            return -1;
        }
        
        return left + right + root->data;
    }
    
  public:
  
    bool isSumTree(Node* root) 
    {
         return isSum(root) != -1;
    }
};