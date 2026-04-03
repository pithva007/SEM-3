#include <bits/stdc++.h>
using namespace std;
typedef long double ld;

long double area(long double r) {
    return 3.14 * r * r;
}
long double area(long double l, long double b) {
    return l * b;
}

long double area(long double b, long double h, int) {
    return 0.5 * b * h;
}

int main() 
{
    ld r, l, b, h;

    cout << "Enter radius of the circle: ";
    cin >> r;
    cout << "Area of Circle: " << area(r) << endl;

    cout << "Enter length and breadth of the rectangle: ";
    cin >> l >> b;
    cout << "Area of Rectangle: " << area(l, b) << endl;

    cout << "Enter base and height of the triangle: ";
    cin >> b >> h;
    cout << "Area of Triangle: " << area(b, h, 0) << endl;

    return 0;
}
