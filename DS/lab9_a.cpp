#include <iostream>
using namespace std;

int main() {
    int n, x;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    cin >> x;

    int l = 0, r = n - 1;
    bool found = false;

    while(l <= r) {
        int mid = (l + r) / 2;

        if(a[mid] == x) {
            cout << "Number Found at index: " << mid << endl;
            found = true;
            break;
        }

        if(a[mid] < x)
            l = mid + 1;
        else
            r = mid - 1;
    }

    if(!found)
        cout << "Not Found\n";

    return 0;
}
