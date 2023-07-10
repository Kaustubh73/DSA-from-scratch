#include <bits/stdc++.h>
using namespace std;

class Node {

    public:
        int data;
        Node * left;
        Node * right;
        int c;
        Node(int x) {
            data = x;
            left = NULL;
            right = NULL;
            c = 1;
            }
};

Node * insert(Node * root, int key, int& maj)
{
    if (root == NULL)
    {
        if (maj == 0)
            maj = 1;
             
        root = new Node(key);
        return root;
    }
    
    if (key < root->data)
    {
        root->left = insert(root->left, key, maj);
    }
    else if (key > root->data)
    {
        root->right = insert(root->right, key, maj);
    }
    else
        root->c++;

    maj = max(maj, root->c);
    return root;
}

void inorder(Node * root, int s)
{
    if (root != NULL) 
    {
        inorder(root->left, s);
        if (root->c > (s / 2))
            cout << root->data << endl;
        inorder(root->right,s);
    }
    return;
}

int countOccurences(vector<int>& nums, int num) {
    int count = 0 ; 
    for (int i = 0 ; i < nums.size() ; i++)
    {
        if (nums[i] == num) {
            count++;
        }
    }
    return count;
}

int findMajorityElement(vector<int>& nums, int left, int right)
{
    if (left == right)
    {
        return nums[left];
    }
    int mid = left + (right - left) / 2;

    int leftMajority = findMajorityElement(nums, left, mid);
    int rightMajority = findMajorityElement(nums, mid + 1, right);

    if (leftMajority == rightMajority)
    {
        return leftMajority;
    }

    int leftCount = countOccurences(nums, leftMajority);
    int rightCount = countOccurences(nums, rightMajority);

    return (leftCount > rightCount) ? leftMajority : rightMajority;
}
int majorityElement(vector<int>& nums)
{
    int left = 0;
    int right = nums.size() -1;
    return findMajorityElement(nums, left, right);
}

int main()
{
    vector<int> nums = {1, 2, 2, 2, 3, 4, 2, 2, 5};

    int majority = majorityElement(nums);

    if (countOccurences(nums, majority) > nums.size() / 2) {
        cout << "Majority element: " << majority << endl;
    } else {
        cout << "No majority element" << endl;
    }
    return 0;
}