#include<bits/stdc++.h>
using namespace std;

inline int max(int a, int b) {
    return (a > b) ? a : b;
}
int main()
{
    int a,b;
    cout<<"Enter two numbers : ";
    cin>>a>>b;

    int maximum = max(a,b);
    
    cout << "Maximum of " << a << " and " << b << " is: " << maximum << endl;


}