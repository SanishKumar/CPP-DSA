#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int key)
{
    int start = 0;
    int end = size - 1;

    int mid = start + (end - start) / 2;

    while (start <= end)
    {
        if (arr[mid] == key)
        {
            // cout << mid;
            return mid;
        }
        if (key > arr[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    return false;
}

int main()
{
    int arr[3][3] = {{2, 3, 4}, {3, 7, 9}, {4, 5, 6}};
    for (int i = 0; i < 3; i++)
    {
        int Index = binarySearch(arr[i], 3, 6);
        if (Index != false)
            cout << i << " " << Index << endl;
    }
}