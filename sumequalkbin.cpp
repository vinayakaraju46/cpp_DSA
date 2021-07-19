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

class BinTree
{
    public:
        Node *root;
        map<int,int>mp;
        BinTree()
        {
            root = NULL;
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
                node->right = insertNode(val, node->right);
            }
            return node;
        }

        
        Node *flathem()
        {
            stack<Node *> stk;
            Node *ans = root;
            
            while(root != NULL || stk.size() != 0)
            {
                if(root->right != NULL)
                {
                    stk.push(root->right);
                }
                root->right = root->left;
                root->left = NULL;
                if(root->right == NULL && stk.size() != 0)
                {
                    root->right = stk.top();
                    stk.pop();
                }
                root = root->right;
            }
            return ans;
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
           cout << node->data << endl;
           if(node->right)
           {
               traverseinorder(node->right);
           }
       }

       void traverseflat(Node *node)
       {
           Node *curr = node;
           while(curr)
           {
               cout << curr->data << " ";
                curr = curr->right;
           }

       }

    //    void inorder(Node *node)
    //    {
    //        if(node->left)
    //        {
    //            inorder(node->left);
    //        }
    //        mp.insert(make_pair(node->data,K-node->data));
    //        if(node->right)
    //        {
    //            inorder(node->right);
    //        }
    //    }
};

int main()
{
BinTree bin;
int n,elem;
cin >> n;
for(int i=0; i<n; i++)
{
    cin >> elem;
    bin.insert(elem);
}
bin.display();
Node * x = bin.flathem();
bin.traverseflat(x);


    return 0;
}