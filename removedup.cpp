#include<iostream>
#include<bits/stdc++.h>

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
        Node<T> *tail;
        map<int,int> dict;
        map<int,int>::iterator itr;
        int size;
        LinkedList()
        {
            head = NULL;
            tail = NULL;
            size = 0;
        }

        LinkedList<T> &insert(const T &val)
        {
            Node<T> *newNode = new Node<T>(val);

            if(head == NULL)
            {
                tail = head = newNode;
            }
            else
            {
                tail->next = newNode;;
                tail = newNode;
            }
            
            return *this;
        }

        LinkedList<T> &removeNode(const T &val)
        {
            Node<T> *curr = head,*prev = NULL;
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

        void display(void)
        {
            Node<T> *actualNode = head;
            while(actualNode)
            {
                cout << actualNode->data << " ";
                actualNode = actualNode->next;
            }
        }

        LinkedList<T> &removedups(void)
        {
            Node<T> *curr = head;
            Node<T> *prev = NULL;
            while(curr)
            {   
                itr = dict.find(curr->data);

                if(curr->data == itr->first)
                {
                    if(prev == NULL)
                    {
                        head = curr->next;
                    }
                    else
                    {
                        prev->next = curr->next;
                    }
                    
                }
                else if(dict.find(curr->data) == dict.end())
                {
                    dict.insert(pair<int,int>(curr->data,0));
                    prev = curr;

                }
                curr = curr->next;
            }
            return *this;

        }

};




int main()
{

LinkedList<int> ll;
int n,elem;
cout << "Enter the number of elements in a LinkedList.." << endl;
cin >> n;
for(int i=0; i<n; i++)
{
    cin >> elem;
    ll.insert(elem);
}

// ll.display();
ll.removedups();
cout << endl;
ll.display();

    return 0;
}