#include <bits/stdc++.h>
using namespace std;

struct nodee {
    int content;
    nodee* nextPtr;
};

nodee* beginning = nullptr;

void insert(int num) {
    nodee* node = new nodee{num, nullptr};
    if (!beginning)
        beginning = node;
    else {
        nodee* walk = beginning;
        while (walk->nextPtr != nullptr)
            walk = walk->nextPtr;
        walk->nextPtr = node;
    }
}

void lookFor(int searchVal) {
    nodee* ref = beginning;
    int index = 1;

    while (ref != nullptr) {
        if (ref->content == searchVal) {
            cout << "Found " << searchVal << " at position " << index << ".\n";
            return;
        }
        ref = ref->nextPtr;
        index++;
    }

    cout << "Sorry, " << searchVal << " was not found.\n";
}

int main() {
    insert(11);
    insert(22);
    insert(33);

    int findVal;
    cout << "Enter number to search: ";
    cin >> findVal;

    lookFor(findVal);

    return 0;
}
