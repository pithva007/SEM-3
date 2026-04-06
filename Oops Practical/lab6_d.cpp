#include <iostream>
using namespace std;

class CountObjects {
    
    static int count;

public:
 
    CountObjects() {
        count++;
    }

  
    static int getCount() {
        return count;
    }
};


int CountObjects::count = 0;

int main() {
    CountObjects c1;
    CountObjects c2;
    CountObjects c3;

    cout << "Number of objects created: " << CountObjects::getCount() << endl;

    return 0;
}