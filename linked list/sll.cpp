#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;
};
node* root = NULL;

void printing();
void searching(int val);
void printFirst();
void printLast();
void printSecondLast();
void printReverse(node *current_node);
void insertFirst(int val);
void delFirst();
void insertLast(int val);
void delLast();
int listSize();
void insertByValue(int val);
void insertByPosition(int val, int pos);
void delByValue(int val);
void delByPosition(int pos);

int main(void)
{
    insertLast(10);

    insertLast(15);

    insertLast(20);

    insertLast(25);

    printing();

    delByPosition(4);

    cout << endl;
    printing();

    return 0;
}

void printing()
{
    node *current_node = root;
    while (current_node != NULL)
    {
        cout << current_node -> data << " ";
        current_node = current_node -> next;
    }
}


void searching(int val)
{
    node *current_node = root;

    while (current_node != NULL)
    {
        if (current_node -> data == val)
        {
            cout << "\nFound!" << endl;
            break;
        }
        current_node = current_node -> next;
    }

    if (current_node == NULL)
        cout << "\nNot found!" << endl;
}


void printFirst()
{
    node *current_node = root;

    if (current_node != NULL)
        cout << current_node -> data << endl;
}


void printLast()
{
    node *current_node = root;

    while(current_node->next != NULL)
    {
        current_node = current_node -> next;
    }
    cout << current_node -> data << endl;
}


void printSecondLast()
{
    node *current_node = root;

    if (current_node == NULL || current_node->next == NULL)
        return;

    while (current_node->next->next != NULL)
    {
        current_node = current_node->next;
    }
    cout << current_node->data << endl;
}


void printReverse(node *current_node)
{
    if (current_node != NULL)
    {
        printReverse(current_node -> next);
        cout << current_node->data << " ";
    }
}


void insertFirst(int val)
{
    node *temp = new node;
    temp->data = val;
    temp->next = root;
    root = temp;
}


void delFirst()
{
    node *current_node = root;
    if (current_node != NULL)
        root = current_node->next;
}


void insertLast(int val)
{
    node *temp = new node;
    temp->data = val;
    temp->next = NULL;

    if (root == NULL)
    {
        root = temp;
        return;
    }

    node *current_node = root;
    while (current_node->next != NULL)
    {
        current_node = current_node->next;
    }
    current_node->next = temp;
}


void delLast()
{
    node *current_node = root;
    if (current_node != NULL)
    {
        if (current_node->next == NULL)
        {
            root = NULL;
            return;
        }

        while (current_node->next->next != NULL)
        {
            current_node = current_node->next;
        }
        current_node->next = NULL;
    }
}


int listSize()
{
    node *current_node = root;
    int count = 0;

    while (current_node != NULL)
    {
        count++;
        current_node = current_node->next;
    }
    return count;
}


void insertByValue(int val)
{
    node *temp = new node;
    temp->data = val;
    node *current_node = root;

    if (current_node == NULL || current_node->data > val)
    {
        temp->next = current_node;
        root = temp;
        return;
    }

    while (current_node->next != NULL && current_node->next->data < val)
    {
        current_node = current_node->next;
    }
    temp->next = current_node->next;
    current_node->next = temp;
}


void insertByPosition(int val, int pos)
{
    node *temp = new node;
    temp->data = val;
    node *current_node = root;

    if (current_node == NULL || pos == 0)
    {
        temp->next = current_node;
        root = temp;
        return;
    }

    int count = 0;
    while (current_node->next != NULL && count < pos-1)
    {
        current_node = current_node->next;
        count++;
    }
    temp->next = current_node->next;
    current_node->next = temp;
}


void delByValue(int val)
{
    node *current_node = root;

    if (current_node != NULL)
    {
        if (current_node->data == val)
        {
            root = current_node->next;
            return;
        }

        while (current_node->next != NULL)
        {
            if (current_node->next->data == val)
            {
                current_node->next = current_node->next->next;
                break;
            }
            current_node = current_node->next;
        }
    }
}


void delByPosition(int pos)
{
    node *current_node = root;

    if (current_node != NULL)
    {
        if (pos == 0)
        {
            root = current_node->next;
            return;
        }

        int count = 0;

        while(current_node->next != NULL)
        {
            if (count == pos-1)
            {
                current_node->next = current_node->next->next;
                return;
            }
            count++;
            current_node = current_node->next;
        }
    }
}
