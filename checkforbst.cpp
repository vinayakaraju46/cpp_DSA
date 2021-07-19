#include<bits/stdc++.h>

using namespace std;

class Node
{
    public:
        int data;
        Node *left ;
        Node *right;
        Node(const int &val)
        {
            data = val;
            left = NULL;
            right = NULL;
        }
};

class Trees
{
    public:
        Node *root;
        int size;
        Trees()
        {
            root = NULL;
            size = 0;
        }

        Trees &insert(const int &val)
        {
            root = insertNode(val,root);
        }

        Node *insertNode(const int &val, Node *node)
        {
            if(node == NULL)
            {
                return new Node(val);
            }
            else if(val < node->data)
            {
                node->left = insertNode(val, node->left);
            }
            else if(val > node->data)
            {
                node->right = insertNode(val, node->right);
            }
            return node;
        }
        void display()
        {
            traverseinorder(root);
        }

        void traverseinorder(Node *node)
        {
            if(node->left)
            {
                traverseinorder(node->left);
            }
            cout << node->data << " ";
            if(node->right)
            {
                traverseinorder(node->right);
            }
        }

        void checkforBst()
        {
            checktraversal(root);
        }

        void checktraversal(Node *node)
        {
            
        }


};




int main()
{

Trees tt;
int n,elem;
cin >> n;
for(int i=0; i<n; i++)
{
    cin >> elem;
    tt.insert(elem);
}
tt.display();



    return 0;
}