#include <bits/stdc++.h>
using namespace std;
typedef long double ld;


class calculator 
{
public:
    ld r,l,b,base,h;

    ld acircle() 
    {
        return 3.14*r*r;
    }

    ld arectangle() 
    {
        return l*b;
    }

    ld atrinagle() 
    {
        return 0.5*base*h;
    }
};

int main() {
    calculator calc;

    cout<<"Enter radius of the circle: ";
    cin>>calc.r;
    cout<<"Area of Circle: "<<calc.acircle()<<endl;

    cout<<"Enter length and breath of the rectangle: ";
    cin>>calc.l>>calc.b;
    cout<<"Area of Rectangle: "<<calc.arectangle()<<endl;

    cout<<"Enter base and height of the triangle: ";
    cin>>calc.base>>calc.h;
    cout<<"Area of Triangle: "<<calc.atrinagle()<<endl;

    return 0;
}