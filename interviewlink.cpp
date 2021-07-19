#include<bits/stdc++.h>

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

class LinkedList
{
    public:
    Node *head,*tail;
    stack<int> stk;
    int size;
    LinkedList()
    {
        tail = head = NULL;
        size = 0;
    }

    LinkedList &insert(const int &val)
    {   size = size + 1;
        Node *newNode = new Node(val);
        if(head == NULL && tail == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        return *this;
    }

    void display()
    {
        Node *curr = head;
        while(curr)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }
    }

    bool checkpalindrome()
    {
        Node *p = head;
        Node *q = head;
        while(p!=NULL && p->next!=NULL)
        {
            stk.push(q->data);
            q = q->next;
            p = p->next->next;
        }

        if(p != NULL)
        {
            q = q->next;
        }
        while(q!=NULL)
        {
            int temp = stk.top();
            stk.pop();
            if(temp != q->data)
            {
                return false;
            }
            q = q->next;
        }
        return true;

    }
    
    LinkedList &removedups()




};




int main()
{
LinkedList ll,ll2;
int N,n,m,elem;
cin >> N;
for(int i=0; i<N; i++)
{
    cin >> elem;
    ll.insert(elem);
}
cout << ll.checkpalindrome();



    return 0;
}