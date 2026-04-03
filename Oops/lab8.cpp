#include <iostream>
using namespace std;

class Complex {
    float real;
    float imag;

public:
    Complex(float r = 0.0, float i = 0.0) {
        real = r;
        imag = i;
    }

    void display() {
        cout << real << " + " << imag << "i" << endl;
    }

    operator float() {
        return real;
    }
};

int main() {
    int a;
    float b;

    cout << "Enter an integer: ";
    cin >> a;

    b = a;
    cout << "Implicit conversion from int to float: b = " << b << endl;

    float c;
    cout << "Enter a float: ";
    cin >> c;

    int d = (int)c;
    cout << "Explicit conversion from float to int: d = " << d << endl;

    float r, i;
    cout << "Enter real part of complex number: ";
    cin >> r;
    cout << "Enter imaginary part of complex number: ";
    cin >> i;

    Complex comp1(r, i);
    cout << "Complex number entered: ";
    comp1.display();

    float realPart = comp1;
    cout << "Conversion from Complex to float (real part): " << realPart << endl;

    return 0;
}


