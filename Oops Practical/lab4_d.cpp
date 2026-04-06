#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[10];
    cout<<"Enter 10 integers:\n";
    for (int i = 0; i < 10; i++) 
    {
        cin>>arr[i];
    }

    sort(arr, arr + 10);

    cout<<"Sorted array: ";
    for (int i = 0; i < 10; i++) 
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    int target;
    cout<<"Enter the number to search: ";
    cin>>target;

    int low=0, high=9, mid;
    bool found=false;

    while (low <= high)
    {
        mid=(low + high) / 2;

        if (arr[mid]==target) 
        {
            found=true;
            break;
        } 
        else if (arr[mid] <= target) 
        {
            low=mid + 1;
        } else {
            high=mid - 1;
        }
    }

    if (found)
        cout<<"Number "<<target<<" found at position "<<mid + 1<<" (1-based index)."<<endl;
    else
        cout<<"Number not found in the array."<<endl;

    return 0;
}
