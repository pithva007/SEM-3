#include <iostream>
using namespace std;

class Point {
public:
    int x;

   
    Point(int val = 0) : x(val) {}

   
    Point(const Point &p) {
        x = p.x;
    }
};

int main() {
    Point p1(10); 
    cout << "p1 x: " << p1.x << endl;

    Point p2(p1);  
    cout << "p2 x: " << p2.x << endl;

    return 0;
}
