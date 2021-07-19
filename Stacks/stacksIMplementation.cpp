#include <bits/stdc++.h>

using namespace std;

class Node
{
    public:
        int data;
        Node *next;

        Node (const int &val)
        {
            data = val;
            next = NULL;
        }
};

class stackList
{
    public:
        Node *head, *tail;

        stackList()
        {
            head = tail = NULL;
        }

        Node *push(const int &val)
        {
            Node *newNode = new Node(val);

            if(head == NULL && tail == NULL) {
                head = tail = newNode;
            }
            else {
                newNode->next = head;
                head = newNode;
            }
            return head;
        }

        Node *top()
        {
            if(head != NULL) {
                return head;
            }
        }

        Node *pop() {
            Node *temp = head;
            
            
            head = head->next;
            
            if(head == NULL)
            {
                cout << "Stack is Empty" << endl;
            }
            return temp;
        }

        void display() {
            Node *curr = head;
            while(curr)
            {
                cout << curr->data << " ";
                curr = curr->next;
            }
        }
};

int
main()
{
    int n, elem, p;
    stackList stk1;
    stk1.push(1);
    stk1.push(2);
    stk1.push(90);
    stk1.pop();
    stk1.pop();
    stk1.pop();
    stk1.display();
    

    return 0;
}