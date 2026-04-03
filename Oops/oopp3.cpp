#include<bits/stdc++.h>
using namespace std;

class Person
{
public:
    string name;
    int age;
    Person(string name, int age)
    {
        this->name = name;
        this->age = age;
    }

};

class Student : public Person{
public:
    int roll ;
    Student(string name,int age,int roll) : Person(name,age){
        this->roll = roll;
        cout << "This is derived class" << endl;
    }
    void getInfo()
    {
        cout << "Name : " << name << endl;
        cout << "Age : " << age << endl;
        cout << "Roll : " << roll << endl;
    }
};

int main()
{
    Student s1("Khush",20,101);
    s1.getInfo();
    return 0;
}   