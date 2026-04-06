#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cout<<"Enter the size of first array: ";
    cin>>n;
    int a[n];
    cout<<"Enter the elements of first array: ";
    for (int i = 0; i < n; i++) 
    {
        cin>>a[i];
    }

    cout<<"Enter the size of second array: ";
    cin>>m;
    int b[m];
    
    cout<<"Enter the elements of second array: ";
    for (int i = 0; i < m; i++) 
    {
        cin>>b[i];
    }

    int finalsize=n+m;
    int ans[finalsize];

    for (int i = 0; i < finalsize; i++) 
    {
        if (i<n)
            ans[i]=a[i];
        else
            ans[i]=b[i-n];
    }

    cout<<"Final merged array is: ";
    for (int i = 0; i < finalsize; i++) 
    {
        cout<<ans[i]<<" ";
    }

    cout<<endl;
    return 0;
}
