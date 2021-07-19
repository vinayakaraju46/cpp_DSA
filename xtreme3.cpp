#include<bits/stdc++.h>

using namespace std;

class Node
{
    public:
        int data;
        int height;
        Node *left;
        Node *right;
        Node(const int &val,int count)
        {
            data = val;
            left = NULL;
            right = NULL;
            height = count;
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

        int calcHeight(Node *node)
        {
            if(node == NULL)
            {
                return 1;
            }
            return node->height;
        }

        Node *insert(const int &val)
        {
            root = insertNode(val, root,1);
        }

        Node *insertNode(const int &val, Node *node, int count)
        {
            if(node == NULL)
            {
                cout << count;
                return new Node(val,count);
            }
            if(val < node->data | val == node->data)
            {
                node->left = insertNode(val, node->left,count+1);
            }
            if(val > node->data)
            {
                node->right = insertNode(val, node->right,count+1);
            }
           
            // node->height = max(calcHeight(node->left),calcHeight(node->right)) + 1;
            return node;
        }

       

    // void topView(Node * root) 
    // {
    //     map<int,int> dict;
    //         map<int,int>::iterator itr;
    //         queue<pair<Node*,int> > que;
    //         Node *temp = NULL;
    //         que.push(pair<Node*,int>(root,1));
    //         while(que.size() != 0)
    //         {
    //             temp = que.front().first;
    //             int d = que.front().second;
    //             que.pop();
                
    //             dict.insert(pair<int,int>(d,temp->data));
                
    //             if(temp->left)
    //             {
    //                 que.push(pair<Node*,int>( temp->left, d+1 ));
    //             }
    //             if(temp->right)
    //             {
    //                 que.push(pair<Node*,int>( temp->right, d+1 ));
    //             }
    //         }
    //     for(itr=dict.begin();itr!=dict.end();++itr)
    //     {
    //         cout << itr->first << " ";
    //     }

    // }

        

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
            cout << node->data << " , "<< node->height << endl;
            if(node->right)
            {
                traverseinorder(node->right);
            }
        }

};



int main()
{BinTree tr;
int n,elem;
cin >> n;
for(int i=0; i<n; i++)
{
    cin >> elem;
    tr.insert(elem);
    cout << endl;
}
// tr.topView(tr.root);
// tr.traverse();

    return 0;
}