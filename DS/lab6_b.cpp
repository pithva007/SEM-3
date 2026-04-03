#include <bits/stdc++.h>
using namespace std;



void mheap(int arr[], int n, int i)
{
    int largest = i; 
    int left = 2 * i + 1; 
    int right = 2 * i + 2; 

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        mheap(arr, n, largest);
    }
}
void builmheap(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        mheap(arr, n, i);
}
void heapsort(int arr[], int n)
{
    builmheap(arr, n);

    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        mheap(arr, i, 0);
    }
}

int main()
{
    int arr[]={5,4,1,10,100,20,8};
    int n=sizeof(arr)/sizeof(arr[0]);
    heapsort(arr, n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}