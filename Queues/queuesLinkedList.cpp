#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(const int &val)
    {
        data = val;
        next = NULL;
    }
};

class QueueList
{
public:
    Node *head, *tail;

    QueueList()
    {
        head = tail = NULL;
    }

    Node *push(const int &val)
    {
        Node *newNode = new Node(val);

        if (head == NULL && tail == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        return head;
    }

    Node *top()
    {
        if (head != NULL)
        {
            return head;
        }
    }

    Node *pop()
    {
        Node *temp = head;

        head = head->next;

        if (head == NULL)
        {
            cout << "Queue is Empty" << endl;
        }
        return temp;
    }

    void display()
    {
        Node *curr = head;
        while (curr)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }
    }
};

int main()
{
    int n, elem, p;
    QueueList q;
    q.push(1);
    q.push(2);
    q.push(90);
    
    cout << "popped: " << q.pop()->data << endl;
    q.display();

    return 0;
}