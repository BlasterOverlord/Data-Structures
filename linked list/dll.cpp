#include <bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    node *next;
    node *prev;
};
node* root = NULL;
node* tail = NULL;

void printing();
void searching(int val);
void printFirst();
void printLast();
void printSecondLast();
void printReverse();
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
    insertLast(5);
    insertLast(10);
    insertLast(15);
    insertLast(20);

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
    cout << endl;
}

void insertFirst(int val)
{
    node *temp = new node;
    temp->data = val;
    temp->prev = NULL;
    if (root == NULL)
    {
        temp->next = NULL;
        root = temp;
        tail = temp;
    }
    else
    {
        root->prev = temp;
        temp->next = root;
        root = temp;
    }
}

void delFirst()
{
    if (root != NULL)
    {
        if (root == tail)
        {
            root = NULL;
            tail = NULL;
        }
        else
        {
            root->next->prev = NULL;
            root = root->next;
        }
    }
}


void insertLast(int val)
{
    node *temp = new node;
    temp->data = val;
    temp->next = NULL;

    if (tail == NULL)
    {
        temp->prev = NULL;
        root = temp;
        tail = temp;
    }
    else
    {
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}


void delLast()
{
    if (tail != NULL)
    {
        if (root == tail)
        {
            root = NULL;
            tail = NULL;
        }
        else
        {
            tail->prev->next = NULL;
            tail = tail->prev;
        }
    }
}


void printFirst()
{
    if (root != NULL)
        cout << root->data << endl;
}


void printLast()
{
    if (tail != NULL)
        cout << tail->data << endl;
}


void printSecondLast()
{
    if (tail!=NULL && tail->prev!=NULL)
        cout << tail->prev->data << endl;
}


void printReverse()
{
    node *current_node = tail;
    while(current_node != NULL)
    {
        cout << current_node->data << " ";
        current_node = current_node->prev;
    }
    cout << endl;
}


void searching(int val)
{
    node *current_node = root;

    while (current_node != NULL)
    {
        if (current_node->data == val)
        {
            cout << "Found!" << endl;
            return;
        }
        current_node = current_node->next;
    }
    cout << "Not Found." << endl;
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

    if (root == tail)
    {
        if (root == NULL)
        {
            temp->next = NULL;
            temp->prev = NULL;
            root = temp;
            tail = temp;
        }
        else if (root->data >= val)
        {
            current_node->prev = temp;
            temp->next = current_node;
            temp->prev = NULL;
            root = temp;
        }
        else
        {
            current_node->next = temp;
            temp->next = NULL;
            temp->prev = current_node;
            tail = temp;
        }
    }
    else
    {
        while(current_node!=tail && current_node->data < val)
        {
            current_node = current_node->next;
        }
        if (current_node == tail)
        {
            if (current_node->data < val)
            {
                current_node->next = temp;
                temp->prev = current_node;
                temp->next = NULL;
                tail = temp;
            }
            else
            {
                current_node->prev->next = temp;
                temp->prev = current_node->prev;
                temp->next = current_node;
                current_node->prev = temp;
            }
        }
        else if (current_node == root)
        {
            current_node->prev = temp;
            temp->next = current_node;
            temp->prev = NULL;
            root = temp;
        }
        else
        {
            current_node->prev->next = temp;
            temp->prev = current_node->prev;
            temp->next = current_node;
            current_node->prev = temp;
        }
    }

}


void delByValue(int val)
{
    if (root != NULL)
    {
        node *current_node = root;

        while (current_node != NULL)
        {
            if (current_node->data == val)
            {
                if (root == tail)
                {
                    root = NULL;
                    tail = NULL;
                }
                else if (current_node == root)
                {
                    current_node->next->prev = NULL;
                    root = current_node->next;
                }
                else if (current_node == tail)
                {
                    current_node->prev->next = NULL;
                    tail = current_node->prev;
                }
                else
                {
                    current_node->prev->next = current_node->next;
                    current_node->next->prev = current_node->prev;
                }
                break;
            }
            current_node = current_node->next;
        }
    }
}


void insertByPosition(int val, int pos)
{
    node *temp = new node;
    temp->data = val;

    if (root == NULL)
    {
        temp->next = NULL;
        temp->prev = NULL;
        root = temp;
        tail = temp;
    }
    else if (pos <= 0)
    {
        root->prev = temp;
        temp->next = root;
        temp->prev = NULL;
        root = temp;
    }
    else if (pos >= listSize())
    {
        tail->next = temp;
        temp->next = NULL;
        temp->prev = tail;
        tail = temp;
    }
    else
    {
        int counter = 0;
        node *current_node = root;
        while (counter != pos)
        {
            counter++;
            current_node = current_node->next;
        }
        current_node->prev->next = temp;
        temp->next = current_node;
        temp->prev = current_node->prev;
        current_node->prev = temp;
    }
}


void delByPosition(int pos)
{
    if (root != NULL)
    {
        int counter = 0;
        node *current_node = root;
        while (current_node != NULL)
        {
            if (counter == pos)
            {
                if (root == tail)
                {
                    root = NULL;
                    tail = NULL;
                }
                else if (current_node == root)
                {
                    current_node->next->prev = NULL;
                    root = current_node->next;
                }
                else if (current_node == tail)
                {
                    current_node->prev->next = NULL;
                    tail = current_node->prev;
                }
                else
                {
                    current_node->prev->next = current_node->next;
                    current_node->next->prev = current_node->prev;
                }
                break;
            }

            counter++;
            current_node = current_node->next;
        }
    }
}
