/*
// Sample code to perform I/O:

cin >> name;                            // Reading input from STDIN
cout << "Hi, " << name << ".\n";        // Writing output to STDOUT

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here
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
            head = tail = NULL;
            size = 0;
        }
        
        LinkedList &insert(const int &val)
        {   Node *newNode = new Node(val);
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
        
        LinkedList &reverse()
        {
            Node *p=head;
            Node *q = head;
            while( p != NULL && q != NULL)
            {   
                if((p->data)%2 == 0)
                {

                    while((p->data)%2 == 0)
                    {
                        stk.push(p->data);
                        p = p->next;
                        if(p == NULL)
                        {
                            break;
                        }
                    }
                    while(stk.size()!=0)
                    {
                        q->data = stk.top();
                        q = q->next;
                        stk.pop();
                        if(q == NULL)
                        {
                            break;
                        }
                    }

                }
                else if(p->data%2 != 0)
                {
                    p = p->next;
                    q = q->next;

                }
                
            }

            // for(stack<int> dump = stk; !dump.empty(); dump.pop())
            // {
            //     cout << dump.top() << " " ;
            // }

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
    int N,elem;
    cin >> N;
    for(int i=0; i<N; i++)
    {   cin >> elem;
        ll.insert(elem);
    }
    ll.reverse();
    ll.display();
    
    
    
    
    
    return 0;
}