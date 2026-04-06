#include <iostream>
using namespace std;

class Shape {
public:
    virtual double computeArea() = 0;
    virtual ~Shape() {}
};

class Triangle : public Shape {
    double b, h;
public:
    Triangle(double x, double y) 
    {
        b = x;
        h = y;
    }
    double computeArea() override { return 0.5 * b * h; }
};

class Rectangle : public Shape {
    double w, l;
public:
    Rectangle(double x, double y)  {
        w = x;
        l = y;
    }
    double computeArea() override { return w * l; }
};


int main() {
    double tb, th, rw, rl;

    cout << "Enter base and height of triangle: ";
    cin >> tb >> th;

    cout << "Enter width and length of rectangle: ";
    cin >> rw >> rl;

    Shape* tri = new Triangle(tb, th);
    Shape* rec = new Rectangle(rw, rl);

    cout << "Triangle Area: " << tri->computeArea() << "\n";
    cout << "Rectangle Area: " << rec->computeArea() << "\n";

    delete tri;
    delete rec;
    return 0;
}


