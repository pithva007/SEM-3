#include <bits/stdc++.h>
using namespace std;

class Employee {
private:
    int emp_id;
    string name;
    string designation;
    double salary;
public:
    void getData();
    void display();
};

void Employee::getData() {
    cout << "Enter Employee ID: ";
    cin >> emp_id;
    cin.ignore(); 

    cout << "Enter Name: ";
    getline(cin, name);

    cout << "Enter Designation: ";
    getline(cin, designation);

    cout << "Enter Salary: ";
    cin >> salary;
    cout << "-----------------------------" << endl;
}


void Employee::display() {
    cout << "Employee ID   : " << emp_id << endl;
    cout << "Name          : " << name << endl;
    cout << "Designation   : " << designation << endl;
    cout << "Salary        : " << salary << endl;
    cout << "-----------------------------" << endl;
}

int main() {
    
    Employee emp1, emp2, emp3;

    cout << "Enter details of Employee 1:" << endl;
    emp1.getData();

    cout << "Enter details of Employee 2:" << endl;
    emp2.getData();

    cout << "Enter details of Employee 3:" << endl;
    emp3.getData();

    cout << "\nEmployee Details:\n";
    emp1.display();
    emp2.display();
    emp3.display();

    return 0;
}
