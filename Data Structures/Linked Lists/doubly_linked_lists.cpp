#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node * next;
    node * prev;
    node(int x) {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

node * insertBegin(node * head, int x)
{
    node * temp = new node(x);
    temp->next = head;

    if (head != NULL)
    {
        head->prev = temp;
    }
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
    temp->prev = curr;
    return head;
}

void insertPos(node * prev_node, int x)
{
    if (prev_node == NULL)
    {
        return;
    }

    node * new_node = new node(x);
    new_node->next = prev_node->next;
    new_node->prev = prev_node;
    prev_node->next = new_node;

    if (new_node->next != NULL)
    {
        new_node->next->prev = new_node;
    }
    return;
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
    head = insertEnd(head, 5);
    insertPos(head, 8);
    printList(head);
    // cout << result->data;
    return 0;
}
