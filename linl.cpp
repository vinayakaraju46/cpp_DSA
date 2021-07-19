#include<iostream>

using namespace std;

template<class T>
class Node
{
    public:
    T data;
    Node<T> *nextNode;
    Node(const T &val)
    {
        data = val;
        nextNode = NULL;
    }

};

template<class T>
 class LinkedList
 {
     public:
     Node<T> *head;
     int size;
     LinkedList()
     {
         head = NULL;
         size = 0;
     }

     LinkedList<T> &insert(const T &val)
     {
         Node<T> *newNode = new Node<T>(val);
         if (head == NULL)
         {
             head = newNode;
         }
         else
         {
             newNode->nextNode = head;
             head = newNode;
         }
         return *this;
     }

     LinkedList<T> &insertend(const T &val)
     {
         Node<T> *newNode = new Node<T>(val);
         Node<T> *curr = head;
         while(curr->nextNode != NULL)
         {
             curr = curr->nextNode;
         }
         curr->nextNode = newNode;

         return *this;
     }

    LinkedList<T> &remove(const T &val)
    {
        Node<T> *prev = NULL;
        Node<T> *curr = head;
        while(curr->data != val)
        {
            prev = curr;
            curr = curr->nextNode;
        }
        if(prev == NULL)
        {
            head = curr->nextNode;
        }
        else
        {
            prev->nextNode = curr->nextNode;
        }
        return *this;
    }

    void display()
    {
        Node<T> *curr = head;
        while(curr)
        {
            cout << curr->data << endl;
            curr = curr->nextNode;
        }
    }

 };



int main()
{
int n,elem,del;
LinkedList<int> ll;
cout << "Enter the number of elements in a list.." << endl;
cin >> n;
for (int i=0; i<n; i++)
{
    cin >> elem;
    ll.insert(elem);
}

ll.display();



    return 0;
}