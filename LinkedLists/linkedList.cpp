#include <bits/stdc++.h>

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
    Node *head, *tail;

    LinkedList()
    {
        head = tail = NULL;
    }

    Node *insert(const int &val)
    {
        Node *newNode = new Node(val);

        if (head == NULL && tail == NULL)
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

    Node *insertAtEnd(const int &val)
    {
        Node *newNode = new Node(val);

        if (tail->next == NULL)
        {
            tail->next = newNode;
            tail = newNode;
        }

        return head;
    }

    Node *deleteNode(const int &val)
    {
        Node *curr = head;
        Node *prev = NULL;
        Node *temp = NULL;

        while (curr->data != val)
        {
            temp = curr->next;
            prev = curr;
            curr = temp;
        }
        if (prev == NULL)
        {
            head = curr->next;
        }
        else
        {
            prev->next = curr->next;
        }
        return head;
    }

    bool checkForPalindrome()
    {
        Node *p = head;
        Node *q = head;
        stack<int> stk;

        while (p != NULL && p->next != NULL)
        {
            stk.push(q->data);
            q = q->next;
            p = p->next->next;
        }

        if (p->next == NULL && p != NULL)
        {
            q = q->next;
        }
        while (q)
        {
            int temp = stk.top();
            stk.pop();
            if (temp != q->data)
            {
                return false;
            }
            q = q->next;
        }
        return true;
    }

    Node *removeDuplicate()
    {
        Node *dummy = new Node(0);
        dummy->next = head;
        Node *prev = dummy;
        Node *curr = head;

        while (curr)
        {
            while (curr->next != NULL && prev->next->data == curr->next->data)
            {
                curr = curr->next;
            }
            if (prev->next == curr)
            {
                prev = prev->next;
            }
            else
            {
                prev->next = curr->next;
            }
            curr = curr->next;
        }
        return head;
    }

    Node *mergeTwoSortedList(LinkedList l1, LinkedList l2)
    {
        Node *p = l1.head;
        Node *q = l2.head;
        Node *s = NULL;
        Node *newHead = NULL;

        if (p->data <= q->data)
        {
            s = p;
            p = s->next;
        }
        else
        {
            s = q;
            q = s->next;
        }
        newHead = s;
        while (p && q)
        {
            if (p->data <= q->data)
            {
                s->next = p;
                s = p;
                p = s->next;
            }
            else if (q->data < p->data)
            {
                s->next = q;
                s = q;
                q = s->next;
            }
        }

        if (p == NULL)
        {
            s->next = q;
        }
        else if (q == NULL)
        {
            s->next = p;
        }
        head = newHead;
        return head;
    }

    Node *removeDupsTwo()
    {
        map<int, int> dict;
        map<int, int>::iterator itr;
        Node *curr = head;
        Node *prev = NULL;

        while (curr)
        {
            itr = dict.find(curr->data);
            if (itr->first == curr->data)
            {
                if (prev == NULL)
                {
                    head = curr->next;
                }
                else
                {
                    prev->next = curr->next;
                }
            }
            else if (itr == dict.end())
            {
                dict.insert(pair<int, int>(curr->data, 0));
                prev = curr;
            }
            curr = curr->next;
        }
        return head;
    }

    Node *removeNthFromENd(const int n)
    {
        Node *curr = head;
        Node *prev = NULL;
        int count = 0;
        while (curr)
        {
            count++;
            curr = curr->next;
        }
        curr = head;
        if (count <= n)
        {
            head = curr->next;
        }
        else
        {
            for (int i = 0; i < (count - n); i++)
            {
                prev = curr;
                curr = curr->next;
            }
            if (prev == NULL)
            {
                head = curr->next;
            }
            else
            {
                prev->next = curr->next;
            }
        }
        return head;
    }

    Node *KReverseLinkedList(const int k)
    {
        Node *prev = NULL;
        Node *p = head;
        Node *temp = NULL;
        Node *a = head;
        Node *tempo = head;
        int count = 1;
        int b = 1;

        if (k == 1 || k == 0)
        {
            return head;
        }

        while (p != NULL)
        {
            prev = NULL;
            b = 1;

            while (b <= k)
            {
                temp = p->next;
                p->next = prev;
                prev = p;
                p = temp;
                b++;
            }

            if (count == 1)
            {
                head = prev;
            }
            a->next = p;
            if (count > 1)
            {
                tempo->next = prev;
                tempo = a;
            }
            a = p;
            count++;
        }
        return head;
    }

    void display()
    {
        Node *curr = head;

        while (curr)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }
    }
};

int main()
{
    int n, elem, delem, m, melem;
    cout << "Enter the number of elements in a LinkedList1" << endl;
    cin >> n;
    LinkedList l1;
    LinkedList l2;

    for (int i = 0; i < n; i++)
    {
        cin >> elem;
        l1.insert(elem);
    }
    // l1.removeDupsTwo();
    // l1.removeNthFromENd(1);
    l1.KReverseLinkedList(2);
    l1.display();
    cout << endl;
    // cout << "Enter the node to be deleted" << endl;
    // cin >> delem;
    // l1.deleteNode(delem);
    // cout << "LinkedList after deletion" << endl;
    // l1.display();
    // bool isPalindrome = l1.checkForPalindrome();
    // if (isPalindrome)
    // {
    //     cout << "It is a palindrome" << endl;
    // }
    // else if (!isPalindrome)
    // {
    //     cout << "Not a palindrome" << endl;
    // }
    // cout << "Sorted Linked List after deletion of duplicates" << endl;
    // l1.removeDuplicate();
    // l1.display();
    // cout << "Enter number of elements in LinkedList2" << endl;
    // cin >> m;

    // for (int i = 0; i < m; i++)
    // {
    //     cin >> melem;
    //     l2.insert(melem);
    // }
    // Node *mergeList = l1.mergeTwoSortedList(l1, l2);
    // l1.display();
}