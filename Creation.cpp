#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
}*root=NULL;

node *creation(node *root, int data)
{
    node *p = new node(data);
    if (!root)
    {
        root = p;
        return root;
    }
    if (!root->left)
    {
        root->left = creation(root->left, data);
    }
    else if (!root->right)
    {
        root->right = creation(root->right, data);
    }
    else
    {
        // If both left and right children are already present,
        // recursively call creation on the right child.
        root->right = creation(root->right, data);
    }
    return root;
}

void display(node *root)
{
    if (root)
    {
        display(root->left);
        cout << root->data << " ";
        display(root->right);
    }
}

int main()
{
    root = creation(root, 10);
    root = creation(root, 20);
    root = creation(root, 30);
    root = creation(root, 40);
    root = creation(root, 50);

    display(root);
    return 0;
}
