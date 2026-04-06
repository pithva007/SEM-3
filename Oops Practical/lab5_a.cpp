#include <bits/stdc++.h>
using namespace std;

class Employee {
private:
    int emp_id;
    string name;
    string designation;
    double salary;
public:

    Employee(int id, string n, string d, double s);
    void display();
};

Employee::Employee(int id, string n, string d, double s) {
    emp_id = id;
    name = n;
    designation = d;
    salary = s;
}

void Employee::display() {
    cout << "Employee ID   : " << emp_id << endl;
    cout << "Name          : " << name << endl;
    cout << "Designation   : " << designation << endl;
    cout << "Salary        : " << salary << endl;
    cout << "-----------------------------" << endl;
}

int main() {

    Employee emp1(101, "Khush Pithva", "Software Engineer", 600000);
    Employee emp2(102, "Parth Savliya", "Devloper", 55000);
    Employee emp3(103, "Priyansh Patel", "Free lancer", 50000);
    emp1.display();
    emp2.display();
    emp3.display();

    return 0;
}
