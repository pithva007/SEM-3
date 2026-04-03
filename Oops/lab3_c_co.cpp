#include<bits/stdc++.h>
using namespace std;

class data{
public:
    void display(int num) 
    {
        cout << "Integer: " << num << endl;
    }

    void display(float num) 
    {
        cout << "Float: " << num << endl;
    }

    void display(string text) {
        cout << "String: " << text << endl;
    }
};
int main()
{
    data obj;
    int i = 10;
    float f = 3.14;
    string s = "Khush Pithva";
    obj.display(i);
    obj.display(f);
    obj.display(s);

}