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

int main(int argc, char * argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    node *head = new node(3);
    head = insertBegin(head, 4);
    head = insertBegin(head, 2);
    head = insertBegin(head, 4);  
    head = insertPos(head, 1, 5);
    node * headA = new node(5);
    headA = insertBegin(headA, 3);
    headA = insertBegin(headA, 2);
    headA = insertBegin(headA, 9);
    headA = insertBegin(headA, 8);

    node * result = addTwoNumbers(head, headA);
    printList(head);
    printList(headA);
    printList(result);
    return 0;
}
