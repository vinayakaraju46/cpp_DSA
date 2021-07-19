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

        Node *insert(const int &val)
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
            return head;
        }

        int checkforPalindrome(LinkedList A)
        {
            Node *p = A.head;
            Node *q = A.head;
            stack<Node *>   stk;
            while(p!=NULL && p->next!=NULL)
            {
                stk.push(q);
                q = q->next;
                p = p->next->next;
            }
            
            if(p == NULL)
            {
                while(q != NULL)
                {
                    Node *temp = stk.top();
                    if(temp->data == q->data)
                    {
                        q = q->next;
                        stk.pop();
                    }
                    else if(temp->data != q->data)
                    {
                        return  0; 
                    }
                    
                }
        
            }

            else if(p->next == NULL)
            {
                q = q->next;
                while(q != NULL)
                {
                    Node *temp = stk.top();
                    if(temp->data == q->data)
                    {
                        q = q->next;
                        stk.pop();
                    }
                    else if(temp->data != q->data)
                    {
                        return  0; 
                    }
                    
                }
            
            }
            return 1;
            
        }

        Node * RemoveDuplicateNode(LinkedList A)
        {
            Node *curr = A.head;
            map<int,int> dict;
            map<int,int>::iterator itr;
            Node *prev = NULL;

            while(curr != NULL)
            {
                itr = dict.find(curr->data);
                if(curr->data == itr->first)
                {
                    if(prev == NULL)
                    {
                        A.head = curr->next;
                    }
                    else
                    {
                        prev->next = curr->next;
                    }
                    
                }
                if(itr == dict.end())
                {
                    dict.insert(pair<int,int>(curr->data,0));
                    prev = curr;
                    curr = curr->next;
                }
                curr = curr->next;
            }
            return A.head;
        }

        void traverse(Node *node)
        {
            Node *curr = node;
            while(curr != NULL)
            {
                cout << curr->data << " " << endl;
                curr = curr->next;
            }
        }

};


int main()
{
    int n;
    int elem;
    LinkedList ll;
    cout << "Enter the number of elements in a LinkedList: " << endl;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> elem;
        ll.insert(elem);
    }
    ll.traverse(ll.head);
    cout << endl;
    cout << ll.checkforPalindrome(ll) << endl;
    cout << "Removing Duplicates" << endl;
    Node *l2 = ll.RemoveDuplicateNode(ll);
    cout << endl;
    ll.traverse(l2);

    
 




    return 0;
}