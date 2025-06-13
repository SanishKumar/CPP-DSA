#include <iostream>
using namespace std;

int peak(int arr[], int s, int e){
    if (s == e) return arr[s];
    int mid = s + (e-s)/2;
    int left = peak(arr, s, mid);
    int right = peak(arr, mid+1, e);

    return max(left, right);
}

int main(){
    int arr[8] = {4,5,6,7,8,1,2,3};
    cout << peak(arr, 0, 7);
    return 0;
}
