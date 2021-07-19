#include<bits/stdc++.h>


using namespace std;

class Node
{
    public :
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
    public :
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

        Node *remove(const int &val)
        {
            root = removeNode(val, root);
            return root;
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
                    cout << "Removing Leaf Node.." << endl;
                    delete node;
                    return NULL;
                }
                else if(node->left != NULL && node->right == NULL)
                {
                    cout << "Removing the node with one left child.." << endl;
                    Node *tempNode = node->left;
                    delete node;
                    return tempNode;
                }
                else if(node->left == NULL && node->right != NULL)
                {
                    cout << "Removing the node with one right child.." << endl;
                    Node *tempNode = node->right;
                    delete node;
                    return tempNode;
                }
                else
                {
                    cout << "Removing the node with Two children .." << endl;
                    Node *tempNode = getPredeccor(node->left);
                    node->data = tempNode->data;
                    node->left = removeNode(tempNode->data, node->left);

                }
                
            }
          return node;  
        }

        Node *getPredeccor(Node *node)
        {
            if(node->right)
            {
                return getPredeccor(node->right);
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
};


int main()
{
    int n,elem;
    Tree tr;
    cout << "Enter the number of elements in a Tree:" << endl;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> elem;
        tr.insert(elem);
    }
    tr.display();

    int d,delem;
    cout << "Enter the number of elements to be deleted.. " << endl;
    cin >> d;
    for(int j=0; j<d; j++)
    {
        cin >> delem;
        tr.remove(delem);
        cout << endl;
        tr.display();
    }
    




    return 0;
}