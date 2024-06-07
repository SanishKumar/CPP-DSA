// 74. Search a 2D Matrix

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size()-1;
        
         int start=0;
         int end=matrix[0].size()-1;
        int ind=-1;
        while(start<=row){
            int mid=start+(row-start)/2;
            if(matrix[mid][0]<=target&&matrix[mid][end]>=target){
                ind=mid;
                break;
            }
            else if(matrix[mid][0]<target){
                start = mid + 1;
            }
            else{
                row=mid-1;
            }
            
        }
        if(ind==-1){
            return false;
        }
        
        start=0;
               
                while(start<=end){
                    int mid=start+(end-start)/2;
                    if(matrix[ind][mid]==target){
                        return true;
                    }
                    else if(matrix[ind][mid]<target){
                       
                          start = mid + 1;
                    }
                    else{
                        end=mid-1;
                    }
                }
        
        return false;
    }
};