#include <iostream>
#include <cmath>
using namespace std;
class Shape {
protected:
    float length;
public:
    virtual void getData()=0;
    virtual void area()=0;
};
class Circle:public Shape {
public:
    void getData() {
        cout<<"Enter radius of Circle: ";
        cin>>length;
    }
    void area() {
        cout<<"Area of Circle: "<<3.14159*length*length<<endl;
    }
};
class Square:public Shape {
public:
    void getData() {
        cout<<"Enter side of Square: ";
        cin>>length;
    }
    void area() {
        cout<<"Area of Square: "<<length*length<<endl;
    }
};
int main() {
    Circle c;
    Square s;
    cout<<"--- Circle ---"<<endl;
    c.getData();
    c.area();
    cout<<"\n--- Square ---"<<endl;
    s.getData();
    s.area();
    return 0;
}

