#include <bits/stdc++.h>
using namespace std;

class summ{
public:
    int num1,num2,num3;
    int sum2()
    {
        return num1+num2;
    }
    int sum3()
    {
        return num1+num2+num3;
    }
    
};


int main() 
{
    summ number;
    cout<<"Enter 3 numbers : ";
    cin>>number.num1>>number.num2>>number.num3;
    cout<<"Sum of first 2 number is "<<number.sum2()<<endl;
    cout<<"Sum of first 2 number is "<<number.sum3()<<endl;


    return 0;
}
