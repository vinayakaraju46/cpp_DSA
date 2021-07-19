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
        LinkedList()
        {
            tail = head = NULL;
            size = 0;
        }
        
        LinkedList &insert(const int &val)
        {   Node *newNode = new Node(val);
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
        
        LinkedList &deleteit(const int val)
        {   int count=0;
            
            
            for(int i=0; i<val; i++)
            {  
                
                Node *curr = head;
                Node *prev = NULL;
                
                while(curr->data > curr->next->data)
                {
                    prev = curr;
                    curr = curr->next;  
                }

                if(curr->data < curr->next->data)
                {
                    if(prev == NULL)
                    {
                        head = curr->next;
                    }
                    else
                    {
                        prev->next = curr->next;
                        curr = curr->next;
                        
                    }
                }
                    
            }
                
              return *this;          
            
        }    

        void deleteall()
        {   Node *curr = NULL;
            while(head != tail)
            {
                curr = head->next;
                free(curr);
                head = curr;
            }

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
 {   LinkedList ll;
    int T,elem;
    long unsigned int N,K;
    cin >> T;
    for(int i=0; i<T; i++)
    {   
        cin >> N;
        cin >> K;
        for(int j=0; j<N; j++)
        {
            cin >> elem;
            ll.insert(elem);
        }
        ll.deleteit(K);
        ll.display();
        ll.deleteall();
        // ll.display();
        cout << endl;
    }
    
    
    
    
    
    return 0;
}