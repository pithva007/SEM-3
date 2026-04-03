#include <bits/stdc++.h>
using namespace std;

int prec(char c) {
    switch (c) {
    case '^': return 3;  
    case '*': case '/': case '%': return 2;
    case '+': case '-': return 1;
    default: return 0;
    }
}

bool isRightAssociative(char c) {
    return (c == '^');
}

struct Stack {
    char arr[1000];
    int top;

    Stack() { top = -1; }

    void push(char c) { arr[++top] = c; }

    char pop() { return arr[top--]; }

    char peek() { return arr[top]; }

    bool empty() { return top == -1; }
};

string Infix_to_Postfix(string s) {
    s = '(' + s + ')';
    Stack st;
    string ans = "";

    for (int i = 0; i < s.size(); i++) {
        char ch = s[i];

        if (ch == ' ') continue;

        if (ch == '(') {
            st.push(ch);
        } 
        else if (ch == ')') {
            while (st.peek() != '(') {
                ans.push_back(st.pop());
                ans.push_back(' '); 
            }
            st.pop();
        } 
        else if (prec(ch) == 0) { 
        
            ans.push_back(ch);
            ans.push_back(' ');
        } 
        else {
            while (!st.empty() && st.peek() != '(' && (prec(st.peek()) > prec(ch) || (prec(st.peek()) == prec(ch) && !isRightAssociative(ch)))) 
            {
                ans.push_back(st.pop());
                ans.push_back(' ');
            }
            st.push(ch);
        }
    }
    return ans;
}

int main() {
    string s;
    cout << "Enter an Expression : ";
    getline(cin, s); 
    cout << "Final Postfix Expression : " << Infix_to_Postfix(s) << endl;
    return 0;
}