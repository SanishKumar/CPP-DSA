#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    // Function to count inversions in the array.
    
    int _merge(int *arr, int s, int e){
        int mid = s + (e-s)/2;
        
        int len1 = mid - s + 1;
        int len2 = e - mid;
        
        int *first = new int[len1];
        int *second = new int[len2];
        
        int k = s;
        for(int i = 0; i < len1; i++){
            first[i] = arr[k++];
        }
        k = mid+1;
        for(int i = 0; i < len2; i++){
            second[i] = arr[k++];
        }
        
        int index1 = 0;
        int index2 = 0;
        k = s;
        int count = 0;
        
        while(index1 < len1 && index2 < len2){
            if(first[index1]>second[index2]){
                count += (len1 - index1);
                arr[k++] = second[index2++];
            }else{
                arr[k++] = first[index1++];
            }
        }
        while(index1 < len1) arr[k++] = first[index1++];
        while(index2 < len2) arr[k++] = second[index2++];
        
        return count;
    }
    
    int _mergeSort(int *arr, int s, int e){
        if(s>=e) return 0;
        int mid = s + (e-s)/2;
        
        int inv = 0;
        inv += _mergeSort(arr, s, mid);
        inv += _mergeSort(arr, mid+1, e);
        
        inv += _merge(arr, s, e);
        return inv;
    }
    
    int inversionCount(vector<int> &arr) {
        // Your Code Here
        int s = 0; 
        int e = arr.size() - 1;
        int mid = s + (e-s)/2;
        
        int n = arr.size();
        int *a = new int[n];
        for (int i = 0; i < n; i++) a[i] = arr[i];
        
        int count = _mergeSort(a, s, e);
        return count;
    }
};