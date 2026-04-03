#include<bits/stdc++.h>
using namespace std; 

int main()
{
	int n;
    cout<<"Enter a number: ";
    cin>>n;

    switch (n%2) 
    {
        case 0:
            cout<<"The number is even."<<endl;
            break;
        case 1: 
            cout<<"The number is odd."<<endl;
            break;
        case -1: 
            cout<<"The number is odd."<<endl;
            break;
    }
     return 0;


}