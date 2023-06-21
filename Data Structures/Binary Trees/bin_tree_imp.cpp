#include <bits/stdc++.h>
using namespace std;

class Node {

    public:
        int data;
        Node * left;
        Node * right;
        Node(int x) {
            data = x;
            left = NULL;
            right = NULL;
            }
};

Node * insertElem(Node * root, int x) {
    if (root == NULL)
    {
        root = new Node(x);
        return root;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty())
    {
        Node * temp = q.front();
        q.pop();
        if (temp->left != NULL)
            q.push(temp->left);
        else {
            temp->left = new Node(x);
            return root;
        }

        if (temp->right != NULL)
            q.push(temp->right);
        else {
            temp->right = new Node(x);
            return root;
        }
    }
}

void deleteDeepest(Node * root, Node * d_node)
{
    queue<Node*> q;
    q.push(root);

    Node * temp;
    while (!q.empty())
    {
        temp = q.front();
        q.pop();

        if (temp == d_node)
        {
            temp = NULL;
            delete (d_node);
            return;
        }

        if (temp->right) {
            if (temp->right == d_node) {
                temp->right = NULL;
                delete (d_node);
                return;
            }  
            else
                q.push(temp->right);
        }

        if (temp->left) {
            if (temp->left == d_node)
            {
                temp->left = NULL;
                delete (d_node);
                return;
            }
            else 
                q.push(temp->left);
        }
    }
}

Node * deletion(Node * root, int key)
{
    if (root == NULL)
        return NULL;

    if (root->left == NULL && root->right == NULL) {
        if (root->data == key)
        {
            return NULL;
        }
        else {
            return root;
        }
    }

    queue<Node *> q;
    q.push(root);

    Node * temp;
    Node * key_node = NULL;
    Node * last;

    while (!q.empty()) {
        temp = q.front();
        q.pop();

        if (temp->data == key)
            key_node = temp;
        
        if (temp->left)
        {
            last = temp;
            q.push(temp->left);
        }
        if (temp->right)
        {
            last = temp;
            q.push(temp->right);
        }
    }

    if (key_node != NULL) {
        int x = temp->data;
        
        if (last->right == temp) 
            last->right = NULL;
        else    
            last->left = NULL;
        delete (temp);
    }
    return root;
}

int maxDepth(Node * root) {
    if (root == NULL)
        return 0;
    else {
        int lDepth = maxDepth(root->left);
        int rDepth = maxDepth(root->right);

        if (lDepth > rDepth) 
            return (lDepth + 1);
        else
            return (rDepth + 1);
    }
}

void printCurrentLevel(Node * root, int level)
{
    if (root == NULL)
    {
        return;
    }
    if (level == 1)
        cout << root->data << " ";
    else if (level > 1)
    {
        printCurrentLevel(root->left, level-1);
        printCurrentLevel(root->right, level-1);
    }
    return;
}

void printLevelOrder(Node * root) 
{
    int h = maxDepth(root);
    for (int i = 1; i <= h; i++)
    {
        printCurrentLevel(root, i);
        // cout << endl;
    }
    return;
}

void printInorder(Node * root)
{
    if (root == NULL)
        return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

void printInorderStack(Node * root)
{
    stack<Node*> s;
    Node * curr = root;

    while (curr != NULL || s.empty() == false)
    {
        while (curr != NULL)
        {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        cout << curr->data << " ";

        curr = curr->right;
    }
    return;
}   


void printPreorder(Node * root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

void printPostorder(Node * root)
{
    if (root == NULL)
        return;
    printPostorder(root->left);
    printPostorder(root->right);
    cout << root->data << " ";
}

int main()
{
    Node * root = new Node(13);
    root = insertElem(root, 43);
    root = insertElem(root, 334);
    root = insertElem(root, 342);
    root = insertElem(root, 42);
    root = insertElem(root, 32);
    root = insertElem(root, 312);

    cout << root->data << endl;
    cout << maxDepth(root) << endl;
    printInorderStack(root);
    return 0;
}