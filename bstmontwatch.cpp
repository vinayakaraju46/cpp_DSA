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
        Node *left;
        Node *right;
        int height;
        Node(const int &val)
        {
            data = val;
            left = NULL;
            right = NULL;
            height = 0;
        }
};

class BinTree
{
    public:
        Node *root;
        int size;
        BinTree()
        {
            root = NULL;
            size = 0;
        }
        int calcHeight(Node *node)
        {
            if(node == NULL)
            {
                return 1;
            }
            return node->height;
        }
        
        BinTree &insert(const int &val)
        {
            root = insertNode(val,root);
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
                node->right = insertNode(val,node->right);
            }
            node->height = max(calcHeight(node->left),calcHeight(node->right)) + 1 ;
            return node;
        }
};





int main()
{   BinTree bin;
    int N,elem;
    cin >> N;
    for(int i=0; i<N;i++)
    {
        cin >> elem;
        bin.insert(elem);
    }
    cout << bin.root->height << endl;
    
    return 0;
}

