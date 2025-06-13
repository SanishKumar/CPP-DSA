#include <bits/stdc++.h>
using namespace std;

int searchRot(int arr[], int lo, int hi, int key) {
    if (lo > hi) return -1;
    int mid = lo + (hi - lo) / 2;
    if (arr[mid] == key) return mid;
    // left half sorted
    if (arr[lo] <= arr[mid]) {
        if (key >= arr[lo] && key < arr[mid])
            return searchRot(arr, lo, mid-1, key);
        else
            return searchRot(arr, mid+1, hi, key);
    }
    // right half sorted
    if (key > arr[mid] && key <= arr[hi])
        return searchRot(arr, mid+1, hi, key);
    return searchRot(arr, lo, mid-1, key);
}

int main(){
    int arr[] = {4,5,6,7,0,1,2}, n=7;
    cout << searchRot(arr,0,n-1,0) << "\n"; 
    cout << searchRot(arr,0,n-1,3) << "\n"; 
    return 0;
}
