#include<bits/stdc++.h>

using namespace std;


template<class T>
class Node
{
    public:
        T character;
        Node<T> *left;
        Node<T> *right;
        Node<T> *middle;
        int val;
        Node(const T &data)
        {
            character = data;
            left = NULL;
            right = NULL;
            val = 0;
        }
};


template<class T>
class TernaryTree
{
    public:
        Node<T> *root;
        int size;
        TernaryTree()
        {
            root = NULL;
            size = 0;
        }

        TernaryTree<T> &insert(string val)
        {   size++;
            root = insertNode(val,root,0);
        }

        Node<T> *insertNode(string val,Node<T> *node, int index)
        {
            char c = val[index];
            if(node == NULL)
            {
                node = new Node<T>(c);
            }
            if(c < node->character)
            {
                node->left = insertNode(val,node->left,index);
            }
            if(c > node->character)
            {
                node->right = insertNode(val,node->right,index);
            }
            if(index < val.length()-1)
            {
                node->middle = insertNode(val,node->middle,index+1);
            }
            else
            {
                node->val = size;
            }
            return node;
        }

        int getval(string key)
        {
            Node<T> *node = getvalNode(root,key,0);
            if(node == NULL)
            {
                return -1;
            }
            return node->val;
        }


         Node<T> *getvalNode(Node<T> *node, string key,int ind)
        {
            if(node == NULL)
            {
                return NULL;
            }
            char c = key[ind];
            if(c < node->character)
            {
                return getvalNode(node->left,key,ind);
            }
            else if(c > node->character)
            {
                return getvalNode(node->right,key,ind);
            }
            if(ind < key.length()-1)
            {
                return getvalNode(node->middle,key,ind+1);
            }
            else
            {
                return node;
            }
            
        } 




};






int main()
{
TernaryTree<int> tt;
int n;
string elem;
cout << "The number of entries would you like to make.." << endl;
cin >> n;
for(int i=0; i<n; i++)
{
    cin >> elem;
    tt.insert(elem);
}
string outpt;
cin >> outpt;
cout << tt.getval(outpt);




    return 0;
}