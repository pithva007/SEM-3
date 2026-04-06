#include<bits/stdc++.h>
using namespace std;

class maximum{
public:
    int num1,num2;
    int maxx()
    {
        return (num1 > num2) ? num1 : num2;
    }

};
int main()
{
    maximum number;
    cout<<"Enter two number : ";
    cin>>number.num1>>number.num2;
    
    cout << "Maximum of " << number.num1 << " and " << number.num2 << " is: " << number.maxx() << endl;
    return 0;

}