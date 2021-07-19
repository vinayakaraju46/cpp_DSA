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
     Node<T> *head,*tail;
     int size;
     LinkedList()
     {
         tail = head = NULL;
         size = 0;
     }

     LinkedList<T> &insert(const T &val)
     {
         Node<T> *newNode = new Node<T>(val);
         if (head == NULL && tail == NULL)
         {
             tail = head = newNode;
         }
         else
         {
             tail->nextNode = newNode;
             tail = newNode;
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
            cout << curr->data << " ";
            curr = curr->nextNode;
        }
    }

    LinkedList<T> &sumlinklist(LinkedList<T> &L,int carry)
    {   
        


    }

 };

int main()
{
int n1,elem1,del,elem2,n2;
LinkedList<int> ll1,ll2;
cout << "Enter the number of elements in a list1.." << endl;
cin >> n1;
for (int i=0; i<n1; i++)
{
    cin >> elem1;
    ll1.insert(elem1);
}

ll1.display();
cout << endl;
cout << "Enter the number of elements in a list2.." << endl;
cin >> n2;
for (int i=0; i<n2; i++)
{
    cin >> elem2;
    ll2.insert(elem2);
}

ll2.display();
cout << endl;
ll1.sumlinklist(ll2);
ll1.display();




    return 0;
}