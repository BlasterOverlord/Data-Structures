#include <bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};
node *root = NULL;

void BST_build(int value)
{
    node *temp = new node();
    temp->data = value;
    temp->left = NULL;
    temp->right = NULL;

    if (root == NULL)
        root = temp;
    else
    {
        node *curr_node = root;
        node *prev_node = root;

        while (curr_node != NULL)
        {
            prev_node = curr_node;
            if (curr_node->data < value)
                curr_node = curr_node->right;
            else
                curr_node = curr_node->left;
        }

        if (prev_node->data < value)
            prev_node->right = temp;
        else
            prev_node->left = temp;
    }
}

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

void findMin()
{
    node *curr_node = root;
    while (curr_node->left != NULL)
    {
        curr_node = curr_node->left;
    }
    cout << "Min: " << curr_node->data << endl;
}

void findMax()
{
    node *curr_node = root;
    while (curr_node->right != NULL)
    {
        curr_node = curr_node->right;
    }
    cout << "Max: " << curr_node->data << endl;
}


void delete_node(int value)
{
    node *curr_node, *prev_node;
    curr_node = prev_node = root;

    while (curr_node != NULL)
    {
        if (curr_node->data == value)
            break;
        prev_node = curr_node;
        
        if (curr_node->data < value)
            curr_node = curr_node->right;
        else
            curr_node = curr_node->left;
    }
    // when bst is empty
    if (curr_node == NULL)
        return;
    
    // when node to be deleted is a leaf node (has no child)
    if (curr_node->left==NULL && curr_node->right==NULL)
    {
        if (prev_node->left == curr_node)
            prev_node->left = NULL;
        else
            prev_node->right = NULL;
    }

    // when node to be deleted has only a single child
    if (curr_node->left==NULL || curr_node->right==NULL)
    {
        node *child;
        if (curr_node->left == NULL)
            child = curr_node->right;
        else
            child = curr_node->left;

        if (prev_node == NULL)
            root = child;
        else if (prev_node->left == curr_node)
            prev_node->left = child;
        else
            prev_node->right = child;
    }


    // when node to be deleted has two children
    if (curr_node->left!=NULL && curr_node->right!=NULL)
    {
        node *temp = prev_node = curr_node;
        curr_node = curr_node->left;
        while (curr_node->right!=NULL)
        {
            prev_node = curr_node;
            curr_node = curr_node->right;
        }
        temp->data = curr_node->data;

        if (prev_node->left==curr_node)
            prev_node->left = curr_node->left;
        else
            prev_node->right = curr_node->left;
    }
}

int main(void)
{
    int x;
    for (int i = 1; i <= 11; i++)
    {
        cin >> x;
        BST_build(x);
    }
    cout << "Inorder: ";
    inorder(root);
    cout << "\n";
    cout << "Preorder: ";
    preorder(root);
    cout << "\n";
    cout << "Postorder: ";
    postorder(root);

    delete_node(12);

    cout << "\n\n" << "---After deleting 12---" << endl;

    cout << "Inorder: ";
    inorder(root);
    cout << "\n";
    cout << "Preorder: ";
    preorder(root);
    cout << "\n";
    cout << "Postorder: ";
    postorder(root); 

    return 0;
}

// 12 6 9 18 4 10 5 16 49 31 43
