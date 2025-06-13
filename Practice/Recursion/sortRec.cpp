#include <iostream>
#include <vector>
using namespace std;



void sort(vector<int>& nums, int n){
    if(n==1) return;

    for(int i = 0; i < n - 1; i++){
        if(nums[i]>nums[i+1]){
            int temp = nums[i];
            nums[i]=nums[i+1];
            nums[i+1]=temp;
        }
    }
    sort(nums,n-1);
}

int main(){
    vector<int> nums = {5,2,3,1};
    sort(nums, nums.size());
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}