#include<bits/stdc++.h>
using namespace std;

int main()
{
	char c;
    float a, b;

    cout<<"Enter operation (+, -, *, /): ";
    cin>>c;
    cout << "Enter two numbers: ";
    cin>>a>>b;

    switch (c) 
    {
        case '+':
            cout<<"Result : "<<a+b<<endl;
            break;
        case '-':
            cout<<"Result : "<<a-b<<endl;
            break;
        case '*':
            cout<<"Result : "<<a*b<<endl;
            break;
        case '/':
            if (b != 0) cout<<"Result:"<<a/b<<endl;
           	else cout<<"Division by zero is not allowed."<<endl;
            break;
        default:
            cout<<"Invalid operator."<<endl;
    }
    return 0;
}