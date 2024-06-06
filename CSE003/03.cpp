#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int key){
    int start = 0;
    int end = size-1;

    int floor = -1;

    int mid = (start+end)/2;

    while(start<=end){
        if(arr[mid]<=key){
            floor = arr[mid];
        }
        if(arr[mid]<key){
            start = mid+1;
        }else if(arr[mid+1]<=key){
            return floor;
        }
        mid=(start+end)/2;
    }
    return floor;
}

int main(){
    int even[8] = {1,2,5,6,7,16,18,19};
    // int odd[5] = {5,6,7,8,9};

    int Index = binarySearch(even , 8, 15);
    cout << Index << endl;

    return 0;
}