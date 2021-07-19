#include<iostream>

using namespace std;

template<class T>
class Node
{
    public:
    T data;
    Node<T> *next;
    Node(const T &val)
    {
        data = val;
        next = NULL;
    }

};

template<class T>
class LinkedListList
{
    public:
    Node<T> *head,*tail;
    int size;
    LinkedListList()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    LinkedListList<T> &insert(const T &val)
    {
        Node<T> *newNode = new Node<T>(val);
        if(head == NULL)
        {
            tail = head = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
        return *this;
        
    }

    LinkedListList<T> &loopinsertion(const T &val)
    {   
        Node<T> *curr = tail;
        Node<T> *rem = tail;
        Node<T> *newNode = new Node<T>(val);
        if(val != tail->data)
        {
            curr->next = newNode;
            curr = curr->next;
        }
        curr->next = tail;
        return *this;

    }

    void display()
    {
        Node<T> *curr = head;
        while(curr)
        {
            cout << curr->data << endl;
            curr = curr->next;
        }

    }
    void displaycycle()
    {
        Node<T> *actualNode = head;
        Node<T> *frontNode = head->next;
        while(actualNode->data != frontNode->data)
        {   cout << actualNode->data << " " << endl; 
            actualNode = actualNode->next;

            frontNode = frontNode->next;
        }
    }

};



int main()
{
LinkedListList<int> ll;
int n,elem,elemc;
cout << "Enter the number of elements in a linear linkedlist.." << endl;
cin >> n;
for(int i=0; i<n; i++)
{
    cin >> elem;
    ll.insert(elem);
}
cout << "Enter the number of elements in a circular linkedlist.." << endl;
int c;
cin >> c;
for(int j=0; j<c; j++)
{   cin >> elemc;
    ll.loopinsertion(elemc);
}
ll.displaycycle();
    return 0;
}