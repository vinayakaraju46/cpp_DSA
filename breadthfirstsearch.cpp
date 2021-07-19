#include<bits/stdc++.h>

using namespace std;

class Node
{
    public:
        int data;
        Node *left;
        Node *right;

        Node(const int &val)
        {
            data = val;
            left = NULL;
            right = NULL;
        }
};

class BSTree
{
    public:
        Node *root;

        BSTree()
        {
            root = NULL;
        }

        Node *insert(const int &val)
        {
            root = insertNode(val, root);
        }

        Node *insertNode(const int &val, Node *node)
        {
            if(node == NULL)
            {
                return new Node(val);
            }
            if(val < node->data)
            {
                node->left = insertNode(val, node->left);
            }
            if(val > node->data)
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


};





int main()
{

    BSTree bst;
    int n;
    int elem;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin>> elem;
        bst.insert(elem);
    }
    
    bst.display();



    return 0;
}