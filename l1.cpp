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
            head = tail = NULL;
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

        Node *removeNode(const int &val) {
            Node *curr = head;
            Node *prev = NULL;

            while(curr->data != val) {
                prev = curr;
                curr = curr->next;
            }
            if(prev == NULL) {
                head = curr->next;
            } else {
                prev->next = curr->next;
            }
            return head;
        }

        Node *reverseLinkedList() {
            Node *curr = head;
            Node *prev = NULL;
            Node *temp = NULL;
            while(curr) {
                temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }
            head = prev;
            return head;
        }

        void traverse() {
            Node *curr = head;
            while(curr != NULL) {
                cout << curr->data << " ";
                curr = curr->next;
            }
        }
        
};

int main() {

    int n,elem;
    LinkedList l1;
    cout << "Enter the number of elements in a LinkedList" << endl;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> elem;
        l1.insert(elem);
    }
    l1.traverse();
    int m, delem;
    cout << "Enter the number of elements to be deleted" << endl;
    cin >> m;
    for(int i=0; i<m; i++) {
        cin >> delem;
        l1.removeNode(delem);
        l1.traverse();
    }
    cout << endl;
    l1.reverseLinkedList();
    l1.traverse();

    return 0;
}