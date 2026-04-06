#include <bits/stdc++.h>
using namespace std;

long double sum(long double a, long double b) 
{
    return a + b;
}
long double sum(long double a, long double b, long double c) 
{
    return a + b + c;
}

int main() {
    long double x,y,z;
    cout<<"Enter 3 numbers : ";
    cin>>x>>y>>z;

    cout<<"Sum of "<<x<<" and "<<y<<" is: "<<sum(x, y)<<endl;

    cout<<"Sum of "<<x<<", "<<y<<" and "<<z<<" is: "<<sum(x, y, z)<<endl;

    return 0;
}
