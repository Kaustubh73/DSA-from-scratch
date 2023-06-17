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
    if (pos < 1) 
    {
        cout << "Invalid position!" << endl;
        return head;
    }
    else {
        while (pos--)
        {
            if (pos == 0)
            {
                node * temp = new node(x);
                temp->next = curr->next->next;
                curr->next = temp;
            }
            else
            {
                if (curr->next == NULL)
                {
                    cout << "Invalid position!" << endl;
                    return head;
                }
                curr = curr->next;
            }
        }
    }
    return head;
}
void deleteNode(node * temp)
{   
    temp->data = temp->next->data;
    temp->next = temp->next->next;
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
    head = insertBegin(head, 43);  
    head = insertBegin(head, 34);
    head = insertPos(head, 2, 5);
    printList(head);
    return 0;
}
