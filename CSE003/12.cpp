#include <iostream>
using namespace std;

int main()
{
    int arr[]={3,2,4,5,6,1};
    int n = 6;
    for (int i = 0; i < n - 1; i++)
    {
        int mi = i;

        for (int j = i + 1; j < n; j++)
        {

            if (arr[j] < arr[mi])
                mi = j;
        }
        swap(arr[mi], arr[i]);
    }
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
}