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
class LinkedList
{

    public:
    Node<T> *head,*tail;
    int size;
    LinkedList()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    LinkedList<T> &insert(const T &val)
    {       size++;
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

    int sizeoflist()
    {
        return size;
    }

    void display()
    {
        Node<T> *curr = head;
        while(curr)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }
    }

    Node<T> *mergepointer(const T &val)
    {
        Node<T> *node = head;
        for(int i=0; i<val; i++)
        {
            node = node->next;
        }
        return node;

    }

    int mergepoint(LinkedList<T> &list, int val)
    {   Node<T> *curr = head;
        Node<T> *curr1 = list.head;
        int x,y,d;
        x = size;
        cout << " " <<endl;
        y = x - val + list.sizeoflist();
        d = x - y;
        // cout << d << endl;
        for(int i=0; i<d; i++)
        {
            curr = curr->next;
        }
        while(curr != curr1)
        {
            curr = curr->next;
            curr1 = curr1->next;
        }
        return curr->data;
    }

};





int main()
{

LinkedList<int> ll, ll1;
int n,elem,n1,elem1;
cout << "Enter the number of elements in a list 1.." << endl;
cin >> n;
for (int i=0; i<n; i++)
{   
    cin >> elem;
    ll.insert(elem);
}
cout << "Enter the number od elements in a list 2.." << endl;
cin >> n1;
for(int j=0; j<n1; j++)
{
    cin >> elem1;
    ll1.insert(elem1);
}
// ll.display();
// ll1.display();
cout << "Merge after ..?" << endl;
int m;
cin >> m;
Node<int> *merger = ll.mergepointer(m);
ll1.tail->next = merger;
ll.display();
cout << " " << endl;
ll1.display();
cout << ll.mergepoint(ll1,m) << endl;
    return 0;
}