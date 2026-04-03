#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    // Input validation
    if (n <= 0) {
        cout << "Invalid size." << endl;
        return 0;
    }

    vector<int> a(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int target;
    cout << "Enter the target element: ";
    cin >> target;

    bool found = false;
    for (int i = 0; i < n; i++) {
        if (a[i] == target) {
            cout << "Element found at position: " << i + 1 << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}
