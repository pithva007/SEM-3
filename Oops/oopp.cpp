#include<bits/stdc++.h>
using namespace std;

class Teacher
{
private:
    double salary;
    string password;
public:
    string name;
    string subject;
    string dept;

    // non parameterized constructor
    Teacher() {
        dept = "CSE";
    }
    // parameterized constructor
    Teacher(string name, string dept, double salary, string subject)
    {
        this->name = name;
        this->dept = dept;
        this->salary = salary;
        this->subject = subject;
    }

    // Copy constructor
    Teacher(const Teacher &orgObj)
    {
        cout << "Copy constructor called" << endl;
        this->name = orgObj.name;
        this->dept = orgObj.dept;
        this->salary = orgObj.salary;
        this->subject = orgObj.subject;
    }

    void getInfo()
    {
        cout << "Name: " << name << endl;
        cout << "subject: " << subject << endl;
    }
};
int main()
{
    Teacher t1("Alice","btech", 50000, "Math");
    //t1.getInfo();
    Teacher t2(t1);
    t2.getInfo();
    return 0;
}