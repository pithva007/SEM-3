#include<bits/stdc++.h>
using namespace std;

class Student
{
public:
    string name;
    double cgpa;
    Student(string name,double cgpa)
    {
        this->name = name;
        this->cgpa = cgpa;
    }

    Student(Student &orgObj)
    {
        this->name = orgObj.name;
        this->cgpa = orgObj.cgpa;
    }

    void getInfo()
    {
        cout << "Name : " << name << endl;
        cout << "cgpa : " << cgpa << endl;
    }

};
int main()
{
    Student s1("Khush",9.5);
    // s1.getInfo();
    Student s2(s1);
    s2.getInfo();
    return 0;
}   