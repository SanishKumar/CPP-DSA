#include <iostream>  
using namespace std;  
  
int linearSearch(int arr[], int n, int target) {  
    for (int i = 0; i < n; i++) {  
        if (arr[i] == target) {  
            return i; // Element found, return its index  
        }  
    }  
    return -1; // Element not found  
}  
  
int main() {  
    int data[] = {12, 45, 78, 23, 56, 89, 67, 34, 90};  
    int n = sizeof(data) / sizeof(data[0]);  
    int target = 67;  
  
    int result = linearSearch(data, n, target);  
  
    if (result != -1) {  
        cout << "Element found at index " << result << endl;  
    } else {  
        cout << "Element not found in the array." << endl;  
    }  
  
    return 0;  
}  