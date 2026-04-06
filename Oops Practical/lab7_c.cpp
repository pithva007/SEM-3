#include <bits/stdc++.h>
using namespace std;

class Person {
    string name;
    int age;
public:
    friend istream& operator>>(istream& in, Person& p) {
        cout << "Enter name: ";
        in >> p.name;
        cout << "Enter age: ";
        in >> p.age;
        return in;
    }
    friend ostream& operator<<(ostream& out, const Person& p) {
        out << "Name: " << p.name << ", Age: " << p.age;
        return out;
    }
};

int main() {
    Person p1;
    cin >> p1;
    cout << p1 << endl;
    return 0;
}
