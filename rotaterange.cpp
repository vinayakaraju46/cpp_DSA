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
        int size;
        stack<int> stk;
        LinkedList()
        {
            tail = head = NULL;
            size = 0;
        }

        LinkedList &insert(const int &val)
        {
            Node *newNode = new Node(val);
            if(head == NULL && tail == NULL)
            {
                tail = head = newNode;
            }
            else
            {
                tail->next = newNode;
                tail = newNode;
            }
            return *this;
            
        }

        LinkedList &reverserangelist()
        {
            Node *p = head;
            Node *temp = NULL;
            Node *q = NULL;
            while(q!=NULL)
            {
                temp = p->next;
                p->next = q;
                q = p;
                p = temp;
            }
            head = q;
            return *this;
            
        }

        void display()
        {
            Node *curr = head;
            while(curr)
            {
                cout << curr->data << " ";
                curr  = curr->next;
            }
        }


};




int main()
{
int N,elem;
LinkedList ll;
cin >> N;
for(int i=0 ;i<N; i++)
{
    cin >> elem;
    ll.insert(elem);
}


ll.display();
ll.reverserangelist();
ll.display();

    return 0;
}
