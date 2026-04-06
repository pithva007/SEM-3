#include <iostream>
#include <string>
using namespace std;
class Person 
{
protected:
    string name;
    int age;
public:
    void getData() {
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Age: ";
        cin >> age;
        cin.ignore();
    }
    void display() {
        cout << "Name: " << name << "\nAge: " << age << endl;
    }
};
class Student : public Person {
private:
    int rollNumber;
public:
    void getData() {
        Person::getData();
        cout << "Enter Roll Number: ";
        cin >> rollNumber;
    }
    void display() {
        cout << "\n=== Student Information ===" << endl;
        Person::display();
        cout << "Roll Number: " << rollNumber << endl;
    }
};
int main() {
    Student s;
    s.getData();
    s.display();
    return 0;
}

