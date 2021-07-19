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
        Node *head;
        Node *tail;

        LinkedList()
        {
            head = NULL;
            tail = NULL;
        }

        LinkedList &insertNode(const int &val)
        {
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

        LinkedList &deleteNode(const int &val)
        {
            Node *curr = head;
            Node *prev = NULL;

            while(val != curr->data)
            {
                prev = curr;
                curr = curr->next;
            }
            if(prev == NULL)
            {
                head = curr->next;
            }
            else
            {
                prev->next = curr->next;
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
};



int main()
{
LinkedList ll;
int n,elem;
cout << "Enter the number of elements in a linkedlist:" << endl;
cin >> n;
for(int i=0; i<n; i++)
{
    cin >> elem;
    ll.insertNode(elem);
}
ll.display();
int d,delem;
cout << "Enter the number of elements to delete.." << endl;
cin >> d;
for(int i=0; i<d; i++)
{
    cin >> delem;
    ll.deleteNode(delem);
    cout << "Linkedlist after deletion.." << endl;
    ll.display();
    cout << endl;
}





    return 0;
}