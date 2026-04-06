#include <bits/stdc++.h>
using namespace std;

struct node {
    int rollno;
    node* next;
};

class ll 
{
private:
    node* head;

public:
    ll() 
    {
        head = nullptr;
    }

    void createList() 
    {
        int value;
        node* temp = nullptr;
        int n;
        cout << "Enter the number of nodes: ";
        cin >> n;

        if (n <= 0) 
        {
            cout << "No nodes to create.\n";
            return;
        }

        for (int i = 0; i < n; i++)
        {
            cout << "Enter roll number " << i + 1 << ": ";
            cin >> value;
            node* newnode = new node{value, nullptr};
            if (head == nullptr) 
            {
                head = newnode;
                temp = head;
            }
            else 
            {
                temp->next = newnode;
                temp = newnode;
            }
        }
    }

    void displayList() const 
    {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        node* temp = head;
        cout << "\nStudent Roll Numbers in the List:\n";
        while (temp != nullptr) 
        {
            cout << "Roll Number: " << temp->rollno << endl;
            temp = temp->next;
        }
    }

    void findRollno(int k) const 
    {
        if (head == nullptr) 
        {
            cout << "List is empty. Can't search.\n";
            return;
        }

        node* temp = head;
        while (temp != nullptr) {
            if (temp->rollno == k) {
                cout << "Roll Number " << k << " is found in the list.\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Roll Number " << k << " not found in the list.\n";
    }

    void deletenode() 
    {
        if (head == nullptr) {
            cout << "List is empty. Cannot delete.\n";
            return;
        }

        int n;
        cout << "Enter the roll number of the node to be deleted: ";
        cin >> n;

        node* temp = head;
        node* prev = nullptr;

        while (temp != nullptr && temp->rollno != n) 
        {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Roll Number " << n << " not found. Cannot delete.\n";
            return;
        }

        if (prev == nullptr) {
            head = head->next;
        } else {
            prev->next = temp->next;
        }

        delete temp;
        cout << "Roll Number " << n << " deleted successfully.\n";
    }

    ~ll() 
    {
        while (head != nullptr) {
            node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    ll list;
    int choice, k;

    list.createList();

    while (true) 
    {
        cout << "\nMenu:\n1. Display List\n2. Find Roll Number\n3. Delete Node\n4. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) 
        {
            case 1:
                list.displayList();
                break;
            case 2:
                cout << "Enter roll number to find: ";
                cin >> k;
                list.findRollno(k);
                break;
            case 3:
                list.deletenode();
                break;
            case 4:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice.\n";
        }
    }

    return 0;
}
