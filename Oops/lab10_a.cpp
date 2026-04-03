#include <iostream>
using namespace std;

class Employee {
private:
    int id;
    string name;
    float salary;

public:
    void setData() {
        cout << "Enter Employee ID: ";
        cin >> id;
        cout << "Enter Employee Name: ";
        cin >> name;
        cout << "Enter Employee Salary: ";
        cin >> salary;
    }

    void displayData() {
        cout << "\n--- Employee Details ---\n";
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Salary: " << salary << endl;
    }
};

int main() {
    Employee emp;
    Employee *ptr;
    ptr = &emp;

    cout << "Enter details of the employee:\n";
    ptr->setData();

    cout << "\nDisplaying employee details using pointer:\n";
    ptr->displayData();

    return 0;
}

