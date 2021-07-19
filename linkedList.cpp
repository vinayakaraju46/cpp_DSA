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
            tail = head = NULL;
            size = 0;
        }

        LinkedList<T> &insert(const T &val)
        {
            Node<T> *newNode = new Node<T>(val);
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

        LinkedList<T> &remove(const T &val)
        {
            Node<T> *prev = NULL;
            Node<T> *curr = head;
            while(curr->data != val)
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

        LinkedList<T> &reversetillk(const int B)
        {
            if(B == 1)
            {
                return *this;
            }
            else
            {
                int k=1;
                Node<T> *p = head;
                Node<T> *prev = NULL;
                Node<T> *temp = NULL;
                Node<T> *a = head;
                // Node<T> *tail1 = head;
                int count = 0;
                while(p)
                {   k=1;
                    prev == NULL; 
                    while(k<=B)
                    {   
                        temp = p->next;
                        p->next = prev;
                        prev = p;
                        p = temp;
                    }
                    count++;
                    if(count == 1)
                    {
                        
                        
                        head = prev;
                    }
                    Node<T> *tempo = a->next;
                    tempo->next = prev;
                    a->next = p;
                    a = p;
                    
                }
                return *this;
            }
            

        }





        void display(void)
        {
            Node<T> *actualNode = head;
            while(actualNode)
            {
                cout << actualNode->data  << " " ;
                actualNode = actualNode->next;
            }
        }
};



int main()
{

int n,elem;
LinkedList<int> list;
cout << "Enter the number of elements in a List.." << endl;
cin >> n;
for(int i=0; i<n; i++)
{
    cin >> elem;
    list.insert(elem);
}

// list.display();
// int ele;
// cin >> ele;
// list.remove(ele);
// list.display();
list.reversetillk(3);
list.display();

    return 0;
}