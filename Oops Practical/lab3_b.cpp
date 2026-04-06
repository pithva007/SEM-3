#include <bits/stdc++.h>
using namespace std;
typedef long double ld;

inline int cube(int number) {
    return number * number * number;
}

int main()
{
    int number;
    cout<<"Enter a number : ";
    cin>>number;
    long long answer = cube(number);
    cout<<"Cube of "<<number<<"is :"<<answer;

    return 0;
}