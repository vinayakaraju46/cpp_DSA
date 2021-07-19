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
            return root;
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

        void zigzagtraversal()
        {
            queue<pair<Node *, int> > q;
            map< int, Node * > main_dict;
            int height=0;

            q.push(make_pair(root,height));

            while(q.size() != 0)
            {
                pair<Node*,int> temp = q.front();
                cout << temp.first->data << " ";
                main_dict.insert(make_pair(temp.second,temp));
                q.pop();
                if(temp.first->left)
                {
                    q.push(make_pair(temp.first->left,temp.second+1));
                }
                if(temp.first->right)
                {
                    q.push(make_pair(temp.first->right,temp.second-1));
                }

            }
            
        }



        void traverse()
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
Tree tr;    
int n,elem;
cin >> n;
for(int i=0; i<n; i++)
{
    cin >> elem;
    tr.insert(elem);
}
tr.traverse();




    return 0;
}