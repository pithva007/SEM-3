#include <iostream>
using namespace std;

int main() {
    int n, x;
    cout << "Enter number of elements: ";
    cin >> n;

    int a[n];
    cout << "Enter elements (sorted): ";
    for(int i = 0; i < n; i++)
        cin >> a[i];

    cout << "Enter value to search: ";
    cin >> x;

    int low = 0, high = n - 1;

    while(low <= high && x >= a[low] && x <= a[high]) {

        if(a[low] == a[high]) { 
            if(a[low] == x)
                cout << "Number found at index: " << low << endl;
            else
                cout << "Not Found\n";
            return 0;
        }

        int pos = low + ((x - a[low]) * (high - low)) / (a[high] - a[low]);

        if(a[pos] == x) {
            cout << "Number found at index: " << pos << endl;
            return 0;
        }

        if(a[pos] < x)
            low = pos + 1;
        else
            high = pos - 1;
    }

    cout << "Not Found\n";
    return 0;
}
