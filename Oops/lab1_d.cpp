#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x,y;
	cout<<"Enter X and Y :";
	cin>>x>>y;
	int temp=x;
	x=y;
	y=temp;
	cout<<"After swap X : "<<x<< " Y : "<<y<<endl;
    return 0;
}