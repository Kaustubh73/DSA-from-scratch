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

Node * insert(Node * root, int key)
{
    if (root == NULL)
    {
        root = new Node(key);
        return root;
    }
    
    if (key < root->data)
    {
        root->left = insert(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = insert(root->right, key);
    }
    return root;
}

void inorder(Node * root)
{
    if (root != NULL) 
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
    return;
}

Node * minValueNode(Node * root)
{
    Node * curr = root;
    while (curr && curr->left != NULL)
    {
        curr = curr->left;
    }
    return curr;
}
Node * deleteNode(Node * root, int data)
{
    if (root == NULL)
        return root;
    if (data < root->data)
    {
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = deleteNode(root->right, data);
    }

    else {
        if (root->left == NULL)
        {
            Node * temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            Node * temp = root->left;
            free(root);
            return temp;
        }

        Node * temp = minValueNode(root->right);

        root->data = temp->data;

        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int Ceil(Node * root, int key)
{
    if (root == NULL)
    {
        return -1;
    }

    if (root->data == key)
        return root->data;
    if (root->data < key)
        return Ceil(root->right, key);
    
    int ceil = Ceil(root->left, key);
    return (ceil >= key) ? ceil : root->data;
}

int prevv = INT_MIN;
bool isBST(Node * root)
{
    if (root == NULL)
        return true;
    if (isBST(root->left) == false) return false;

    if (root->data <= prevv) return false;
    prevv = root->data;

    return isBST(root->right);
}
int main()
{
    Node * root = NULL;
  
    root = insert(root, 50);
    insert(root, 30);  
    insert(root, 20);  
    insert(root, 40);  
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    cout << isBST(root) << endl;
    return 0;
}