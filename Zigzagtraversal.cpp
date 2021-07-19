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


class Tree
{
    public:
        Node *root;

        Tree()
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
            else if(val > node->data)
            {
                node->right = insertNode(val, node->right);
            }
            else if(val < node->data)
            {
                node->left = insertNode(val, node->left);
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


        void topview()
        {
            map<int,int>dist;
            map<int,int>::iterator itr;
            queue< pair<Node *, int> > que;
            que.push(make_pair(root,0));
            dist.insert(make_pair(0,root->data));
            while(que.size() != 0)
            {
                Node *temp = que.front().first;
                int currheight = que.front().second;
                dist.insert(make_pair(currheight,temp->data));
                que.pop();
                if(temp->left)
                {
                    que.push(make_pair(temp->left,currheight-1));
                }
                if(temp->right)
                {
                    que.push(make_pair(temp->right,currheight+1));
                }

            }
            for(itr=dist.begin(); itr!=dist.end(); ++itr)
            {
                cout << itr->second << " ";
            }
        }
        

};


int main()
{
    Tree tr;
    int n,elem;
    cout << "Enter the number of elements in a Tree.." << endl;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> elem;
        tr.insert(elem);
    }
    tr.display();
    cout << endl;
    cout << "Top view of a Tree is .." <<endl;
    tr.topview();





    return 0;
}