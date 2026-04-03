#include <iostream>
using namespace std;

class Person {
public:
    string name;
    Person(string n) {
        name = n;
    }
    void showName() {
        cout << "Name: " << name << endl;
    }
};

class Student : virtual public Person {
public:
    int roll;
    Student(string n, int r) : Person(n) {   // still must call Person() since it’s base
        roll = r;
    }
    void showRoll() {
        cout << "Roll: " << roll << endl;
    }
};

class Employee : virtual public Person {
public:
    int empId;
    Employee(string n, int id) : Person(n) {  // must also call Person()
        empId = id;
    }
    void showEmpId() {
        cout << "Employee ID: " << empId << endl;
    }
};

class WorkingStudent : public Student, public Employee {
public:
    WorkingStudent(string n, int r, int id)
        : Person(n), Student(n, r), Employee(n, id) {
        // all assignments handled by base constructors
    }
};

int main() {
    WorkingStudent ws("Khush", 10, 101);
    ws.showName();
    ws.showRoll();
    ws.showEmpId();
    return 0;
}
