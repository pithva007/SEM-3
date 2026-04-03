#include<bits/stdc++.h>
using namespace std;

class String {
    char str[100];
public:
    String(const char* s = "") {
        strcpy(str, s);
    }

    bool operator==(const String& s) {
        return strcmp(str, s.str) == 0;
    }
};

int main() {
    String s1("hello"), s2("hello"), s3("world");

    if (s1 == s2) // s3 = s1.strcmp(s2);
        cout << "s1 and s2 are equal" << endl;
    else
        cout << "s1 and s2 are not equal" << endl;

    if (s1 == s3)
        cout << "s1 and s3 are equal" << endl;
    else
        cout << "s1 and s3 are not equal" << endl;

    return 0;
}
