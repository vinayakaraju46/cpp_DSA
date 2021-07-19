#include<iostream>
#include<bits/stdc++.h>

using namespace std;


template<class T>
class Node
{
    public:
    T data;
    Node<T> *left;
    Node<T> *right;
    Node<T> *middle;
    int value;
    Node(char alpha)
    {
        data = alpha;
        left = NULL;
        right = NULL;
        middle = NULL;
        value = 0;
    }
        
};

template<class T>
class TernarySearchTree
{
    public:
        Node<T> *root;
        
        TernarySearchTree()
        {
            root = NULL;
        }

        TernarySearchTree<T> &insert(string alpha)
        {
            root = insertNode(alpha,root,0);
        }

        Node<T> *insertNode(string alpha,Node<T>*node,int ind)
        {   T c = alpha[ind];
            if(node == NULL)
            {
                node = new Node<T>(c);
            }
            if(c < node->data)
            {
                node->left = insertNode(alpha,node->left,ind);
            }
            else if(c > node->data)
            {
                node->right = insertNode(alpha,node->right,ind);
            }
            else if(index < alpha.length()-1)
            {
                node->middle = insertNode(alpha,node->middle,ind+1);
            }
            else
            {
                node->val = 0;
            }
            return node;
            
        }

        void showthis(char inchar)
        {
            traversedatabase(root)
        }





};







int main()
{




    return 0;
}