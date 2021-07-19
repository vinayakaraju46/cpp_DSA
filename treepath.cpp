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

        Node *remove(const int &val)
        {
            root = removeNode(val ,root);
        }

        Node *removeNode(const int &val, Node *node)
        {
            if(node == NULL)
            {
                return NULL;
            }
            else if(val < node->data)
            {
                node->left = removeNode(val, node->left);
            }
            else if(val > node->data)
            {
                node->right = removeNode(val, node->right);
            }
            else
            {
                if(node->left == NULL && node->right == NULL)
                {
                    cout << "Removing the leaf node.." << endl;
                    delete node;
                    return NULL;
                }
                else if(node->left != NULL && node->right == NULL)
                {
                    cout << "deleting the node with one left child.." << endl;
                    Node *tempNode = node->left;
                    delete node;
                    return tempNode;
                }
                else if(node->left == NULL && node->right != NULL)
                {
                    cout << "deleting the node with one rightchild.." << endl;
                    Node *tempNode = node->right;
                    delete node;
                    return tempNode;
                }
                else
                {
                    cout << "removing the node with two children.." << endl;
                    Node *tempNode = getpredeccor(node->left);
                    node->data = tempNode->data;
                    node->left = removeNode(tempNode->data,node->left);
                }
                
            }
            return node;
            
        }

        Node *getpredeccor(Node *node)
        {
            if(node->right)
            {
                getpredeccor(node->right);
            }
            return node;
        }

        void pathsum(vector< vector<int> > &vec, vector<int> &row, Node *node,int sum, int B)
        {
            if(node == NULL)
            {
                return ;
            }
            if(node->left == NULL && node->right == NULL)
            {
                sum = sum + node->data;
                if(sum == B)
                {
                    row.push_back(node->data);
                    vec.push_back(row);
                    row.pop_back();
                }
                return ;

            }

            sum = sum + node->data;
            row.push_back(node->data);
            pathsum(vec,row,node->left,sum,B);
            pathsum(vec,row,node->right,sum,B);
            row.pop_back();

        }


        void traverseallpath(vector< vector<int > > &vec, vector<int> &arr, Node *node)
        {   
            if(node == NULL)
            {
                return ;
            }
            if(node->left == NULL && node->right == NULL)
            {
                arr.push_back(node->data);
                vec.push_back(arr);
                arr.pop_back();
            }

            arr.push_back(node->data);
            traverseallpath(vec,arr,node->left);
            traverseallpath(vec,arr,node->right);
            arr.pop_back();


        }

        int rootleafsum(Node *node, int sum)
        {
            if(node == NULL)
            {
                return 0;
            }
            sum = (sum*10 + node->data)%1003;
            if(node->left == NULL && node->right == NULL)
            {
                return sum;
            }
            return (rootleafsum(node->left,sum) + rootleafsum(node->right,sum)) % 1003 ;
        }

        void printlevel(Node *node, int level)
        {
            if(node == NULL)
            {
                return ;
            }
            if(level == 0)
            {
                cout << node->data << " ";
                return ;
            }
            else
            {
                printlevel(node->left,level-1);
                printlevel(node->right,level-1);
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
    Tree tr;
    int n,elem;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> elem;
        tr.insert(elem);
    }
    tr.display();
    // cout << "Enter the number to remove from the node.." << endl;
    // int delelem,m;
    // cin >> m;
    // for(int i=0; i<m; i++)
    // {
    //     cin >> delelem;
    //     tr.remove(delelem);
    //     cout << endl;
    //     tr.display();
    // }
    // cout << "Enter the path sum.." << endl;
    // int sumpath,B;
    // cin >> B;
    // sumpath = 0;
    // vector< vector<int> > vec;
    // vector<int> arr;
    // tr.pathsum(vec,arr,tr.root,sumpath,B);
    // tr.traverseallpath(vec,arr,tr.root);

    // for(int i=0; i<vec.size(); i++)
    // {
    //     for(int j=0; j<vec[i].size(); j++)
    //     {
    //         cout << vec[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << tr.rootleafsum(tr.root,0);
    cout << endl;
    tr.printlevel(tr.root,2);



    return 0;
}