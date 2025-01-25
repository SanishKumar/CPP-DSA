class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	// Code here
    	queue<Node*> q; 
    	vector<vector<int>> tree; 
    	q.push(root) ;
    	int currlvl = 0; 
    	while(!q.empty()) {
    	    tree.push_back({}) ;
    	    int size = q.size() ;
    	    while(size--) {
    	        Node* top = q.front() ;
    	        q.pop() ;
    	        tree[currlvl].push_back(top->data) ;
    	        if(top -> left) q.push(top -> left) ;
    	        if(top -> right) q.push(top -> right) ;
    	    }
    	    currlvl++ ;
    	}
    	vector<int> ans;
    	for(int i = 0; i < tree.size(); i++) {
    	    if(i & 1) {
    	        reverse(tree[i].begin(), tree[i].end()) ;
    	        for(int j = 0; j < tree[i].size(); j++) ans.push_back(tree[i][j]) ;
    	    }
    	    else {
    	        for(int j = 0; j < tree[i].size(); j++) ans.push_back(tree[i][j]) ;
    	    }
    	}
    	return ans ;
    }
};