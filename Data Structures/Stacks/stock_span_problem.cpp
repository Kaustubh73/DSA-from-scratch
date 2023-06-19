#include <bits/stdc++.h>
using namespace std;

#define MAX 1000

class Stack {

    public:
        int top;
        int a[MAX];
        Stack() {top = -1;}
        bool push(int x);
        int pop();
        int peek();
        bool isEmpty();
};

bool Stack::push(int x)
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

int Stack::pop()
{
    if (top < 0)
    {
        cout << "Stack empty" << endl;
        return 0;
    }
    else {
        int x = a[top--];
        return x;
    }
}

int Stack::peek() {
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

vector<int> calculateSpan(vector<int> price, int n, vector<int> S)
{
    class Stack st;
    st.push(0);
    S[0] = 1;

    for (int i = 1 ; i < n ; i++)
    {
        int current_price = price[i];
        while ((!st.isEmpty()) && (price[st.peek()] <= current_price))
        {
        cout << i << " " << st.pop() << endl;

        }
        if (st.isEmpty())
        {
            S[i] = i + 1;
        }
        else
        {
            S[i] = i - st.peek();
        }
        st.push(i);
    }
    return S;
}



int main(int argc, char * argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n = 6;
    vector<int> price = {10, 4, 5, 90, 120,80};
    vector<int> S (n, 0);

    S = calculateSpan(price, n, S);
    for (int i=0 ; i < n; i++)
    {
        cout<< S[i] << " ";
    }
    cout << endl;
    return 0;
}