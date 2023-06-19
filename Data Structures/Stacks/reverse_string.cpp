#include <bits/stdc++.h>
using namespace std;

void reversestring(string s)
{
    stack<string> st;

    for (int i = 0; i < s.length() ;i++)
    {
        string word = "";
        while (s[i] != ' ' && i < s.length())
        {
            word += s[i];
            i++;
        }
        st.push(word);
    }

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}



int main(int argc, char * argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    getline(cin, s);
    reversestring(s);
    return 0;
}