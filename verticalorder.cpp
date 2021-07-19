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

        Tree &insert(const int &val)
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
                node->left = insertNode(val ,node->left);
            }
            if(val > node->data)
            {
                node->right = insertNode(val, node->right);
            }
            return node;
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

        void verticaltraversal()
        {
            queue<Node *> que;
            map<int,vector<int> > mp;
            map<int,vector<int> >::iterator itr;
            vector<int> arr;
            int hd = 0;
            que.push(root);
            arr.push_back(root->data);
            mp.insert(pair<int,vector<int> >(hd,arr));
            while(que.size() != 0)
            {
                Node *temp = que.front();
                que.pop();
                if(temp->left)
                {   vector<int> arri;
                    que.push(temp->left);
                    itr = mp.find(hd-1);
                    if(itr == mp.end())
                    {   
                        arri.push_back(temp->left->data);
                        mp.insert(pair<int,vector<int> >(hd-1,arri));
                    }
                    else
                    {
                        arri.push_back(temp->left->data);
                    }  
                }
                if(temp->right)
                {   
                    vector<int> arri;
                    que.push(temp->right);
                    itr = mp.find(hd+1);
                    if(itr == mp.end())
                    {   
                        arri.push_back(temp->right->data);
                        mp.insert(pair<int,vector<int> >(hd-1,arri));
                    }
                    else
                    {
                        arri.push_back(temp->right->data);
                    }
                }
            }

            vector< vector<int> > vec;
            for(itr=mp.begin();itr!=mp.end();itr++)
            {
                vec.push_back(itr->second);
            }

            for(int j=0; j<vec.size(); j++)
            {
                for(int k=0; k<vec[j].size(); k++)
                {
                    cout << vec[j][k] << " ";
                }
                cout << endl;
            }

        }


};



int main()
{
Tree bin;
int n,elem;
cin >> n;
for(int i=0; i<n; i++)
{
    cin >> elem;
    bin.insert(elem);
}
// bin.traverse();

bin.verticaltraversal();



    return 0;
}