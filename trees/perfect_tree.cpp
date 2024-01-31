#include <bits/stdc++.h>

using namespace std;

struct node{
    int data;
    node *left;
    node*right;
};
node *root = NULL;

queue<node*> q;


void inorder(node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}


void preorder(node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}


void postorder(node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}


void Perfect_build(int value)
{
    node *temp = new node();
    temp->data = value;
    temp->right = NULL;
    temp->left = NULL;

    if (root == NULL)
    {
        root = temp;
        q.push(root);
    }
    else
    {
        if (q.front()->left == NULL)
        {
            q.front()->left = temp;
            q.push(temp);
        }
        else
        {
            q.front()->right = temp;
            q.push(temp);
            q.pop();
        }
    }
}

int main(void)
{
    int x;
    for (int i = 1; i <= 7; i++)
    {
        cin >> x;
        Perfect_build(x);
    }
    cout << "Inorder: ";
    inorder(root);
    cout << "\n";
    cout << "Preorder: ";
    preorder(root);
    cout << "\n";
    cout << "Postrder: ";
    postorder(root);


    return 0;
}

// 12 6 9 18 4 10 5
