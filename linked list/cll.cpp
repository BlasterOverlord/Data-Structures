#include <bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    node *next;
};
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

    insertByValue(1);

    printing();

    return 0;
}

void printing()
{
    if (tail != NULL)
    {
        node *current_node = tail->next;

        do
        {
            cout << current_node->data << " ";
            current_node = current_node->next;

        }
        while (current_node != tail->next);
        cout << endl;
    }
}


void insertFirst(int val)
{
    node *temp = new node;
    temp->data = val;

    if (tail == NULL)
    {
        tail = temp;
        temp->next = temp;
    }
    else
    {
        temp->next = tail->next;
        tail->next = temp;
    }
}


void insertLast(int val)
{
    node *temp = new node;
    temp->data = val;

    if (tail == NULL)
    {
        tail = temp;
        temp->next = temp;
    }
    else
    {
        temp->next = tail->next;
        tail->next = temp;
        tail = temp;
    }
}

void delFirst()
{
    if (tail != NULL)
    {
        if (tail->next == tail)
        {
            tail = NULL;
        }
        else
        {
            tail->next = tail->next->next;
        }
    }
}


void delLast()
{
    if (tail != NULL)
    {
        if (tail->next == tail)
        {
            tail = NULL;
        }
        else
        {
            node *current_node = tail->next;
            while (current_node->next != tail)
            {
                current_node = current_node->next;
            }
            current_node->next = tail->next;
            tail = current_node;
        }
    }
}


void printFirst()
{
    if (tail != NULL)
    {
        cout << tail->next->data << endl;
    }
}


void printLast()
{
    if (tail != NULL)
    {
        cout << tail->data << endl;
    }
}

void printSecondLast()
{
    if (tail != NULL)
    {
        node *current_node = tail->next;
        while(current_node->next != tail)
        {
            current_node = current_node->next;
        }
        cout << current_node->data << endl;
    }
}


void printReverse()
{
    stack<node*> s;
    node *current_node = tail->next;
    do
    {
        s.push(current_node);
        current_node = current_node->next;
    }
    while (current_node != tail->next);

    while(!s.empty())
    {
        cout << s.top()->data << " ";
        s.pop();
    }
    cout << endl;
}


int listSize()
{
    int count = 0;
    if (tail == NULL)
    {
        return count;
    }
    else
    {
        node *current_node = tail->next;
        do
        {
            count++;
            current_node = current_node->next;
        }
        while (current_node != tail->next);
    }
    return count;
}


void searching(int val)
{
    if (tail == NULL)
    {
        cout << "NOT FOUND!" << endl;
    }
    else
    {
        node *current_node = tail->next;
        do
        {
            if (current_node->data == val)
            {
                cout << "Found!" << endl;
                return;
            }
            current_node = current_node->next;
        }
        while (current_node != tail->next);
        cout << "Not Found!" << endl;
    }
}


void insertByValue(int val)
{
    node *temp = new node;
    temp->data = val;
    if (tail == NULL)
    {
        tail = temp;
        temp->next = temp;
    }
    else
    {
        node *current_node = tail;
        do
        {
            if (current_node->next->data > val)
            {
                temp->next = current_node->next;
                current_node->next = temp;
                return;
            }
            current_node = current_node->next;
        }
        while (current_node->next != tail->next);

        insertLast(val);
    }
}


void insertByPosition(int val, int pos)
{
    node *temp = new node;
    temp->data = val;
    node *current_node = tail->next;

    if (tail == NULL || pos >= listSize())
    {
        insertLast(val);
    }
    else if (pos <= 0)
    {
        insertFirst(val);
    }
    else
    {
        int counter = 0;
        do
        {
            if (counter+1 == pos)
            {
                temp->next = current_node->next;
                current_node->next = temp;
                break;
            }
            counter++;
            current_node = current_node->next;
        }
        while (current_node != tail->next);
    }
}


void delByValue(int val)
{
    if (tail != NULL)
    {
        node *current_node = tail;
        do
        {
            if (current_node->next->data == val)
            {
                if (current_node->next == tail)
                {
                    delLast();
                }
                else
                {
                    current_node->next = current_node->next->next;
                }
                break;
            }
            current_node = current_node->next;
        }
        while (current_node->next != tail->next);
    }
}


void delByPosition(int pos)
{
    if (tail != NULL)
    {
        if (pos >= listSize())
        {
            delLast();
        }
        else if (pos <= 0)
        {
            delFirst();
        }
        else
        {
            int counter = 0;
            node *current_node = tail->next;
            do
            {
                if (counter+1 == pos)
                {
                    current_node->next = current_node->next->next;
                    break;
                }
                counter++;
                current_node = current_node->next;
            }
            while (current_node != tail->next);
        }
    }
}
