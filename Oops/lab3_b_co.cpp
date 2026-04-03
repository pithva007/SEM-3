#include<bits/stdc++.h>
using namespace std;

class cubes {
public:
    int number;
    long long cube() 
    {
        return (long long)number*number*number;
    }
};

int main() 
{
    cubes calc;
    cout<<"Enter a number: ";
    cin >> calc.number;
    cout<<"Cube of "<<calc.number<<" is: "<<calc.cube()<<endl;
    return 0;
}