#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the size of array : ";
    cin>>n;
    int arr[n];
    cout<<"Enter "<<n<<" integers: "<<endl;
    for (int i = 0; i < n; i++) 
    {
        cin >> arr[i];
    }
    int large=INT_MIN;
    int slarge=INT_MIN;

    for (int i = 0; i < n; i++) 
    {
        if (arr[i] > large) 
        {
            slarge = large;
            large = arr[i];
        } 
        else if (arr[i] > slarge && arr[i] != large) 
        {
            slarge = arr[i];
        }
    }

    cout << "The second largest number is: " << slarge << endl;


}