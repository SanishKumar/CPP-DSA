#include <iostream>

using namespace std;

int Partition(int *arr, int s, int e){
    int index = s;
    int pivot = arr[index];
    int cnt = 0;
    for(int i = s+1; i <= e; i++){
        if(arr[i] < pivot) cnt++;
    }
    int pindex = s + cnt;
    swap(arr[index], arr[pindex]);
    int i = s, j = e;
    while(i < pindex && j > pindex){
        while(i<pindex && arr[i] < pivot) i++;
        while(j > pindex && arr[j] >= pivot) j--;
        if(i < pindex && j > pindex) {
            swap(arr[i++], arr[j--]);
        }
    }
    return pindex;
}

void quicksort(int *arr, int s, int e){
    if(s>=e) return;

    int p = Partition(arr, s, e);

    quicksort(arr, s, p-1);
    quicksort(arr, p+1, e);
}

int main(){
    int arr[6] = {3, 1, 3, 3, 2, 3};
    quicksort(arr, 0, 5);

    for(int i = 0; i < 6; i++){
        cout << arr[i] << " ";
    }
    return 0;
}