#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node * next;
    node(int x) {
        data = x;
        next = NULL;
    }
};

node * insertBegin(node * head, int x)
{
    node * temp = new node(x);
    temp->next = head;
    return temp;
}

node * insertEnd(node * head, int x)
{
    node * temp = new node(x);
    if (head == NULL) return temp;
    node * curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = temp;
    return head;
}

node * insertPos(node * head, int pos, int x)
{
    node * curr = head;
    node * temp = new node(x);
    if (pos < 1) 
    {
        cout << "Invalid position!" << endl;
        return head;
    }
    else
    {
        int count = 1;
        while (count != pos)
        {
            curr = curr->next;
        }
        temp->next = curr->next;
        curr->next = temp;
    }
    return head;
}
void deleteNode(node * temp)
{   
    temp->data = temp->next->data;
    temp->next = temp->next->next;
}

node * addTwoNumbers(node * A, node * B)
{
    if (A == NULL) return B;
    if (B == NULL) return A;

    stack<int> s1, s2;
    while (A != NULL)
    {
        s1.push(A->data);
        A = A->next;
    }

    while (B != NULL)
    {
        s2.push(B->data);
        B = B->next;
    }
    int carry = 0;
    node * result = NULL;

    while (s1.empty() == false || s2.empty() == false) {
        int a = 0, b = 0;
        if (!s1.empty()) {
            a = s1.top();
            s1.pop();
        }
        if (!s2.empty())
        {
            b = s2.top();
            s2.pop();
        }
        int total = a + b + carry;
        carry = total/ 10;
        node * temp = new node(total % 10);
        if (result == NULL){
            result = temp;
        }
        else 
        {
            temp->next = result;
            result = temp;
        }
    }
    if (carry != 0)
    {
        node * temp = new node(carry);
        temp->next = result;
        result = temp;
    }
    return result;
}
node * getIntersectionNode(node * headA, node * headB)
{
    node * pA = headA;
    node * pB = headB;

    while (pA != pB)
    {
        pA = pA == nullptr ? headB : pA->next;
        pB = pB == nullptr ? headA : pB->next;
    }
    return pA;

}

node * middleNode(node * head)
{
    if (head == NULL) return NULL;

    node * slow = head;
    node * fast = head;

    while ((fast != NULL) && (fast->next != NULL))
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

node * reverseList(node * head)
{
    node * curr = head;
    node * prev = NULL;

    while (curr != NULL)
    {
        node * temp = curr->next;
        curr->next = prev;

        prev = curr;
        curr = temp;
    }
    return prev;
}

node * copyList(node * head)
{
    if (head == NULL)
    {
        return NULL;
    }
    node * newHead = new node(head->data);
    node * curr = head->next;
    node * currCopy = newHead;
    while (curr != NULL)
    {
        currCopy->next = new node(curr->data);
        currCopy = currCopy->next;
        curr = curr->next;   
    }
    return newHead;
}
node * sortList(node * head)
{
    if (head == NULL)
        return NULL;

    else if (head->next == NULL)
    {
        return head;
    }
    else
    {
        vector<int> v;
        node * result = head;
        while (result != NULL)
        {
            v.push_back(result->data);
            result = result->next;
        }
        sort(v.begin(), v.end());
        result = head;
        for (int i = 0; i < v.size() ; i++)
        {
            result->data = v[i];
            result = result->next;
        }
        return head;
    }
}
int printList(node * head)
{
    node * curr = head;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
    return 0;
}

class Queue {
    public:
    node * front;
    node * rear;

    Queue() {front = rear = NULL;}
    
    void enqueue(int x)
    {
        node * temp = new node(x);
        if (rear == NULL)
        {
            front = rear = temp;
            return;
        }

        rear->next = temp;
        rear = temp;
        return;
    }

    void dequeue()
    {
        if (front == NULL)
        {
            cout << "Queue empty\n";
            return;
        }
        node * temp = front;
        front = front->next;

        if (front == NULL)
        {
            rear = NULL;
        }
        delete (temp);
    }
    void display() {
        node * temp;
        if (front == NULL)
        {
            cout << "Queue empty" << endl;
        }
        else {
            temp = front;
            while (temp != NULL)
            {
                cout << temp->data;
                temp = temp->next;
                if (temp != NULL)
                {
                    cout << "->";
                }
            }
            cout << endl;
        }
    }
};

int main(int argc, char * argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    Queue q;
    q.enqueue(10);
    q.enqueue(32);
    q.enqueue(43);
    q.enqueue(433);
    q.dequeue();
    q.enqueue(23);
    cout << q.front->data << endl;
    cout << q.rear->data << endl;
    q.display();
    // cout << result->data;
    return 0;
}
