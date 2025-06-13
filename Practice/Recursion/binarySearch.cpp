#include<iostream>
using namespace std;

int binarySearch(int arr[], int s, int e, int k){
    if(s > e) return -1;
    int mid = s + (e-s)/2;
    if(arr[mid] == k) return mid;

    if(k < mid) return binarySearch(arr, s, mid-1, k);
    else return binarySearch(arr, mid + 1, e, k);
}

int main(){
    int arr[6] = {1,23,24,25,33,54};
    cout << binarySearch(arr, 0, 5, 5) << endl;
}