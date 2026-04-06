#include <iostream>
using namespace std;

class Box {
    double length;
    double breadth;
    double height;

public:
 
    Box(double l, double b, double h)  {
        length = l;
        breadth = b;
        height = h;
    }


    double volume() const {
        return length * breadth * height;
    }

   
    void displayVolume() const {
        cout << "Volume of box: " << volume() << endl;
    }
};

int main() {
    double l, b, h;
    cout << "Enter length, breadth and height of box: ";
    cin >> l >> b >> h;

    Box b1(l, b, h);   
    b1.displayVolume(); 

    return 0;
}
