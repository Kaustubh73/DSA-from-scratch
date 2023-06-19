#include <bits/stdc++.h>
using namespace std;

#define MAX 1000

class Stack {
    public:
        int top;
        char a[MAX];
        Stack() {top = -1;}
        bool push(char x);
        char pop();
        char peek();
        bool isEmpty();
};

bool Stack::push(char x)
{
    if (top >= (MAX-1)) {
        cout << "Stack Overflow" << endl;
        return false;
    }
    else {
        a[++top] = x;
        cout << x << " pushed into stack\n";
        return true;
    }
}

char Stack::pop()
{
    if (top < 0)
    {
        cout << "Stack empty" << endl;
        return 0;
    }
    else {
        char x = a[top--];
        return x;
    }
}

char Stack::peek() {
    if (top < 0)
    {
        cout << "Stack is empty" << endl;
        return 0;
    }
    else {
        int x = a[top];
        return x;
    }
}

bool Stack::isEmpty()
{
    return (top < 0);
}

int isBalanced(string s)
{
    class Stack stk;
    for (int i = 0 ; i < s.length() ; i++)
    {
        if ((s[i] == '(')||(s[i] == '[') || (s[i] == '{'))
        {
            stk.push(s[i]);
        }
        else if (stk.isEmpty() == true)
        {
            return 0;
        }
        else 
        {
            switch(s[i])
            {
                case ')':
                {
                    if (stk.peek() != '(')
                    {
                        return 0;
                    }
                    stk.pop();
                    break;
                }
                case '}':
                {
                    if (stk.peek() != '{')
                        return 0;
                    stk.pop();
                    break;
                }
                case ']':
                {
                    if (stk.peek() != '[')
                        return 0;
                    stk.pop();
                    break;
                }
            }
        }
    }
    if (stk.isEmpty() == false)
    {
        return 0;
    }
    return 1;
}


int main(int argc, char * argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a = "[{()}]";
    if (isBalanced(a))
    {
        cout << "Balanced" << endl;
    }
    else {
        cout << "Not Balanced" << endl;
    }
    return 0;
}