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
            if(head == NULL)
            {
                head = newNode;
            }
            else
            {
                newNode->next = head;
                head = newNode;
            }
            return *this;
        }

        void display(void)
        {
            Node<T> *actualNode = head;
            while(actualNode)
            {
                cout << actualNode->data;
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

list.display();

    return 0;
}