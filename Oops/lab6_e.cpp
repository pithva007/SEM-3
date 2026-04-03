#include <iostream>
using namespace std;

class C {
public:
  
    C() {
        cout << "Constructor called" << endl;
    }

   
    ~C() {
        cout << "Destructor called" << endl;
    }
};

int main() {
    cout << "Program started." << endl;

    C obj1; 

    cout << "Entering a new block..." << endl;
    {
        C obj2;   
    }

    cout << "Back to main function." << endl;

    
    return 0;
}
