#include <bits/stdc++.h>
using namespace std;

class Q {
        public:
        stack<int> s;

        void enqueue(int x)
        {
            s.push(x);
        }

        int dequeue()
        {
            if (s.empty())
            {
                cout << "Queue empty\n";
                return INT_MIN;
            }

            int x = s.top();
            s.pop();
            if (s.empty())
            {
                return x;
            }
            int item = dequeue();
            s.push(x);
            return item;
        }

        bool isEmpty()
        {
            if (s.empty()) return true;
            return false;
        }
};

int main() {
    Q q;
    q.enqueue(43);
    q.enqueue(45);
    q.enqueue(3);
    q.enqueue(43);
    q.dequeue();

    while (!q.isEmpty())
    {
        cout << q.dequeue() << " ";
    }

    cout << endl;
    return 0;
}