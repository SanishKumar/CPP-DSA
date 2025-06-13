#include <iostream>
using namespace std;

int firstOcc(int arr[], int s, int e, int k){
    if(s > e) return -1;
    int mid = s + (e-s)/2;
    if(arr[mid] == k && arr[mid-1]!=k) return mid;

    if(arr[mid] < k) return firstOcc(arr, mid+1, e, k);
    else return firstOcc(arr, s, mid-1, k);
}

int main(){
    int arr[6] = {1,1,2,2,3,4};
    cout << firstOcc(arr, 0, 5, 2);
    return 0;
}