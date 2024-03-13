#include <iostream>
using namespace std;

class bstNode
{
public:
    int data;
    bstNode *left;
    bstNode *right;

    bstNode(int value)
    {
        data = value;
        left = right = NULL;
    }
};

bstNode *Insert(bstNode *root, int data)
{
    if (root == NULL)
    {
        return new bstNode(data);
    }
    else if (data <= root->data)
    {
        root->left = Insert(root->left, data);
    }
    else
    {
        root->right = Insert(root->right, data);
    }
    return root;
}

bool Search(bstNode *root, int data)
{
    if (root == NULL)
    {
        return false;
    }
    else if (root->data == data)
    {
        return true;
    }
    else if (root->data >= data)
    {
        return Search(root->left, data);
    }
    else
    {
        return Search(root->right, data);
    }
}

int main()
{
    bstNode *root = NULL;

    root = Insert(root, 15);
    root = Insert(root, 10);
    root = Insert(root, 13);
    root = Insert(root, 20);
    root = Insert(root, 25);
    root = Insert(root, 22);
    root = Insert(root, 30);
    root = Insert(root, 18);

    int number;
    cout << "enter the number to be searched:" << endl;
    cin >> number;

    if (Search(root, number) == true)
    {
        cout << "Found." << endl;
    }
    else
    {
        cout << "Not Found." << endl;
    }
}