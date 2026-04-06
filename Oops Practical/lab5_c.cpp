#include<bits/stdc++.h>
using namespace std;

class book{
private:
    string title;
    string auther;
    int price;
public:
    void setdata();
    void display();
};

void book :: setdata()
{
    cout<<"Enter the name of book : ";
    cin>>title;
    cout<<"Enter the auther of book : ";
    cin>>auther;
    cout<<"Enter the price of book : ";
    cin>>price;
    cout<<endl;
    
}

void book :: display()
{
    cout<<"Book :"<<title<<endl;
    cout<<"Auther :"<<auther<<endl;
    cout<<"Price :"<<price<<endl;
    cout << "-----------------------------" << endl;


}

int main()
{
    book b1,b2,b3;
    b1.setdata();
    b2.setdata();
    b3.setdata();

    b1.display();
    b2.display();
    b2.display();

}