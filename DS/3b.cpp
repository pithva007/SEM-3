#include <bits/stdc++.h>
using namespace std;

int prec(char c)
{
    switch (c)
    {
    case '*':
    case '/':
    case '%':
        return 2;
    case '-':
    case '+':
        return 1;
    default:
        return 0;
    }
}

struct node
{
    char val;
    node *next;
    node() {}
    node(char x)
    {
        val = x;
        next = NULL;
    };
    node(char x , node* nn )
    {
        val = x;
        next = nn;
    };

    
    char top()
    {
        return this->val;
    }
    node *pop()
    {
        node *t = this->next;
        free(this);
        return t;
    }
    node *push(char x)
    {
        node *nn = new node(x , this);
        return nn;
    }
};

string Infix_to_Postfix(string s)
{
    s = '(' + s + ')';
    node *st = new node();
    string ans = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
            st = st->push(s[i]);
        else if (s[i] == ')')
        {
            while (st->top() != '(')
            {
                ans.push_back(st->top());
                st = st->pop();
            }
            st = st->pop();
        }
        else if (prec(s[i]) == 0)
            ans.push_back(s[i]);
        else
        {
            while (st->top() != '(' && prec(st->top()) >= prec(s[i]))
            {
                ans.push_back(st->top());
                st = st->pop();
            }
            st = st->push(s[i]);
        }
    }
    return ans;
}

int main()
{

    string s;
    cout << "Enter a Expression : ";
    cin >> s;
    cout << "Final Expression : " << Infix_to_Postfix(s) << endl;
    return 0;
}