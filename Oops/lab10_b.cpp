#include <iostream>
using namespace std;

class Employee {
private:
    int id;
    string name;

public:
    void setData(int i, string n) {
        id = i;
        name = n;
    }

    void display() {
        cout << "\nEmployee ID: " << id;
        cout << "\nEmployee Name: " << name << endl;
    }
};

int main() {
    Employee emp;
    Employee *ptr = &emp;

    void (Employee::*setPtr)(int, string) = &Employee::setData;
    void (Employee::*showPtr)() = &Employee::display;

    (ptr->*setPtr)(101, "Harshi");
    (ptr->*showPtr)();

    return 0;
}

