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

void storeBSTNodes(Node * root, vector<Node*> &nodes)
{
    if (root == NULL)
        return;
    
    storeBSTNodes(root->left, nodes);
    nodes.push_back(root);
    storeBSTNodes(root->right, nodes);
}

Node * buildTreeUtil(vector<Node*> &nodes, int start, int end)
{
    if (start > end)
        return NULL;
    
    int mid = (start + end) / 2;
    Node * root = nodes[mid];
    root->left = buildTreeUtil(nodes, start, mid - 1);
    root->right = buildTreeUtil(nodes, mid + 1, end);
    return root;
}
Node * buildTree(Node * root)
{
    vector<Node *> nodes;
    storeBSTNodes(root, nodes);

    int n = nodes.size();
    return buildTreeUtil(nodes, 0, n-1);
}

void printPreorder(Node * root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

int main()
{
  
    Node* root = new Node(10);
    root->left = new Node(8);
    root->left->left = new Node(7);
    root->left->left->left = new Node(6);
    root->left->left->left->left = new Node(5);
 
    root = buildTree(root);
 
    printf("Preorder traversal of balanced "
            "BST is : \n");
    printPreorder(root);
    return 0;
}