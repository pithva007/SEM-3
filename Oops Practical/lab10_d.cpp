#include <iostream>
using namespace std;

class Base {
public:
    virtual void show() {
        cout << "Base class show() function called" << endl;
    }
};

class Derived : public Base {
public:
    void show() override {
        cout << "Derived class show() function called" << endl;
    }
};

int main() {
    Base *ptr;
    Derived d;

    ptr = &d;

    cout << "Calling function using base class pointer pointing to derived object:\n";
    ptr->show();

    return 0;
}

