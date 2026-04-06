#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int age;
public:
    void getPersonData() {
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Age: ";
        cin >> age;
        cin.ignore();
    }
    void displayPerson() {
        cout << "Name: " << name << "\nAge: " << age << endl;
    }
};

class Marks {
protected:
    float marks[6];
public:
    void getMarks() {
        cout << "Enter marks of 6 subjects: ";
        for (int i = 0; i < 6; i++) {
            cin >> marks[i];
        }
    }
    void displayMarks() {
        cout << "Marks: ";
        for (int i = 0; i < 6; i++) {
            cout << marks[i] << (i < 5 ? ", " : "");
        }
        cout << endl;
    }
};

class Result : public Person, public Marks {
    float percentage, cgpa;
    string grade, meaning;
    int gradePoint;
public:
    void calculate() {
        float sum = 0;
        for (int i = 0; i < 6; i++) {
            sum += marks[i];
        }
        percentage = sum / 6;
        cgpa = percentage / 9.5;

        if (percentage >= 91) { grade = "O"; meaning = "Outstanding"; gradePoint = 10; }
        else if (percentage >= 81) { grade = "A+"; meaning = "Excellent"; gradePoint = 9; }
        else if (percentage >= 71) { grade = "A"; meaning = "Very Good"; gradePoint = 8; }
        else if (percentage >= 61) { grade = "B+"; meaning = "Good"; gradePoint = 7; }
        else if (percentage >= 51) { grade = "B"; meaning = "Above Average"; gradePoint = 6; }
        else if (percentage >= 46) { grade = "C"; meaning = "Average"; gradePoint = 5; }
        else if (percentage >= 40) { grade = "P"; meaning = "Pass"; gradePoint = 4; }
        else { grade = "F"; meaning = "Fail"; gradePoint = 0; }
    }

    void displayResult() {
        cout << "\n=== Result ===" << endl;
        displayPerson();
        displayMarks();
        cout << "Percentage: " << percentage << "%" << endl;
        cout << "CGPA: " << cgpa << endl;
        cout << "Grade: " << grade
             << " (" << meaning << ")" << endl;
        cout << "Grade Point: " << gradePoint << endl;
    }
};

int main() {
    Result r;
    r.getPersonData();
    r.getMarks();
    r.calculate();
    r.displayResult();
    return 0;
}


