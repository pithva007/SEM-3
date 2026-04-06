#include <bits/stdc++.h>
using namespace std;

struct Element {
    int info;
    Element* next;
};

Element* headPtr = nullptr;

void pushBack(int v) {
    Element* e = new Element{v, nullptr};
    if (headPtr == nullptr) {
        headPtr = e;
    } else {
        Element* mover = headPtr;
        while (mover->next)
            mover = mover->next;
        mover->next = e;
    }
}

void printList() {
    if (!headPtr) {
        cout << "Nothing to display, list is empty.\n";
        return;
    }

    Element* ptr = headPtr;
    cout << "Current List: ";
    while (ptr) {
        cout << ptr->info << " => ";
        ptr = ptr->next;
    }
    cout << "NULL\n";
}

int main() {
    pushBack(7);
    pushBack(14);
    pushBack(21);
    printList();

    return 0;
}
