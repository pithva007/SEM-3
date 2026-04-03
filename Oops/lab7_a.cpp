#include <bits/stdc++.h>
using namespace std;

class Complex {
    float real, imag;
public:
    Complex(float r = 0, float i = 0) {
        real = r;
        imag = i;
    }

    Complex operator+(const Complex& c) {
        return Complex(real + c.real, imag + c.imag);
    }

    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    Complex c1(3.2, 2.5), c2(1.5, 4.5),c3(1,4);
    Complex c4 = c1 + c2 + c3;
    cout << "Sum: ";
    c4.display();
    return 0;
}
