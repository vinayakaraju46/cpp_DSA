#include<bits/stdc++.h>


using namespace std;

class Node {
    public:
        int data;
        Node *next;

        Node(const int &val) {
            data = val;
            next = NULL;
        }
};

class LinkedList {
    public:
        Node *head;
        Node *tail;

        LinkedList() {
            head = NULL;
            tail = NULL;
        }

        Node *insert(const int &val) {
            Node *newNode = new Node(val);
            if(head == NULL && tail == NULL) {
                head = tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
            return head;
        }
};

void traverse(Node *node) {
    Node *curr = node;
    while(curr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
}

Node *mergeSortedList(Node *l1, Node *l2) {
    Node *p = l1;
    Node *q = l2;
    Node *s = NULL;
    Node *startHead = NULL;
    if(!p) {
        return q;
    } else if(!q) {
        return p;
    } else if(p && q) {
        if(p->data <= q->data) {
            s = startHead = p;
            p = s->next;        
        } else if(p->data > q->data) {
            s = startHead = q;
            q = s->next;
        }
    }

    while(p && q) {
        if(p->data <= q->data) {
            s->next = p;
            s = p;
            p = s->next;
        } else {
            s->next = q;
            s = q;
            q = s->next;
        }
    }
    
    if(p == NULL) {
        s->next = q;
    } else if(q == NULL) {
        s->next = p;
    }
    return startHead;
}

int main() {
    int n, elem, m, delem;
    LinkedList l1, l2;

    cout << "Enter the data for LinkedList 1"<< endl;
    cin >> n;
    for(int j=0; j<n; j++) {
        cin >> elem;
        l1.insert(elem);
    }
    cout << endl;
    cout << "Enter the data for LinkedList 2"<< endl;
    cin >> m;
    for(int j=0; j<m; j++) {
        cin >> delem;
        l2.insert(delem);
    }
    traverse(l1.head);
    cout << endl;
    traverse(l2.head);
    cout << endl;
    cout << "Merging the two Arrays" << endl;
    Node *result = mergeSortedList(l1.head, l2.head);
    traverse(result);
    
    return 0;
}