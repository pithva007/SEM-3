#include <bits/stdc++.h>
using namespace std;
typedef long double ld;

void display(int num) 
{
    cout<<"Integer: "<<num<<endl;
}
void display(float num) 
{
    cout<<"Float: "<<num<<endl;
}
void display(string text) 
{
    cout<<"String: "<<text<<endl;
}

int main() 
{
    int i = 10;
    float f = 3.14;
    string s = "Khush Pithva";
    display(i);  
    display(f);  
    display(s);  

    return 0;
}
