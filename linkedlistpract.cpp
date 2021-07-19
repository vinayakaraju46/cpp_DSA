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

        LinkedList()
        {
            head = NULL;
            tail = NULL;
        }

        LinkedList &insert(const int &val)
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
            return *this;
        }

        LinkedList &deletedup()
        {
            vector<int> mp;
            vector<int>::iterator itr;

            Node *p = head;
            Node *prev = NULL;
            while(p != NULL)
            {
                itr = find(mp.begin(),mp.end(),p->data);
                if(itr == mp.end())
                {
                    mp.push_back(p->data);
                    prev = p;
                    
                }
                else
                {
                    if(prev == NULL)
                    {
                        head = p->next;
                    }
                    else
                    {
                        prev->next = p->next;
                    }
                    
                }
                p = p->next;
                
            }
            return *this;
        }

        LinkedList &removealldups()
        {
            
            Node *newhead = new Node(0);
            newhead->next = head;
            Node *curr = head;
            Node *prev = newhead;

            while(curr)
            {
                while(curr->next != NULL && prev->next->data == curr->next->data)
                {
                    curr = curr->next;
                }
                if(prev->next == curr)
                {
                    prev = prev->next;
                }
                else
                {
                    prev->next = curr->next;
                }
                curr = curr->next;                
            }
            head = newhead->next;
            return *this;
        }



        bool checkpalindrome()
        {
            Node *p = head;
            Node *q = head;
            stack<int> stk;
            while(p && p->next != NULL)
            {
                stk.push(q->data);
                q = q->next;
                p = p->next->next;
            }
            if(p != NULL)
            {
                q = q->next;
            }
            while(q)
            {
                int temp = stk.top();
                stk.pop();
                if(temp != q->data)
                {
                    return false;
                }
                q = q->next;
                
            }
            return true;
        
        }

        LinkedList &reverserange(int m,int n)
        {
            Node *curr = head;
            Node *temp = NULL;
            Node *prev = NULL;

            for(int i=1;i<m;i++)
            {
                prev = curr;
                curr = curr->next;
            }
            Node *savepointer = curr;
            Node *savepointer1 = prev;



            for(int j=m; j<n; j++)
            {
                temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }
            savepointer1->next = prev;
            savepointer->next = curr;
            // head = prev;
            return *this;
        }

        LinkedList &reorderlsit()
        {
            
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
    LinkedList l1;
    int c,elem;
    cin >> c;
    for(int i=0; i<c ; i++)
    {
        cin >> elem;
        l1.insert(elem);
    }
    l1.display();
    // cout << l1.checkpalindrome();
    l1.reverserange(3,5);
    cout << "removing the duplicates.." << endl;
    l1.display();

    return 0;
}