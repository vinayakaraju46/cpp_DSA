#include<iostream>
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
        

        BinTree()
        {
            root = NULL;
        }

        BinTree &insert(const int &val)
        {
            root = insertNode(val,root);
        }

        Node *insertNode(const int &val,Node *node)
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

        void topviewtree()
        {   
            map<int,int> dict;
            map<int,int>::iterator itr;
            queue<pair<Node*,int> > que;
            Node *temp = NULL;
            que.push(pair<Node*,int>(root,0));
            while(que.size() != 0)
            {
                temp = que.front().first;
                int d = que.front().second;
                que.pop();
                
                dict.insert(pair<int,int>(d,temp->data));
                
                if(temp->left)
                {
                    que.push(pair<Node*,int>( temp->left, d-1 ));
                }
                if(temp->right)
                {
                    que.push(pair<Node*,int>( temp->right, d+1 ));
                }
            }
            for(itr=dict.begin();itr!=dict.end();++itr)
        {
            cout << itr->second << " ";
        }

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
BinTree bin;
int n,elem;
cout << "Enter the number of elements in a BinTree.." << endl;
cin >>n;
for(int i=0; i<n; i++)
{
    cin >> elem;
    bin.insert(elem);
}
bin.display();
cout << endl;
bin.topviewtree();






    return 0;
}