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


class trees
{
    public:
        Node *root;

        trees()
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
        

        Node *remove(const int &val)
        {
            root = removeNode(val, root);
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
                    cout << "removing the leaf node.." << endl;
                    delete node;
                    return NULL;
                }
                else if(node->left != NULL && node->right == NULL)
                {
                    cout << "removing the node with one left child.." << endl;
                    Node *tempNode = node->left;
                    delete node;
                    return tempNode;
                }
                else if(node->left == NULL && node->right != NULL)
                {
                    cout << "removing the node with one right child.." << endl;
                    Node *tempNode = node->right;
                    delete node;
                    return tempNode;
                }
                cout << "Removing the node with two children.." << endl;
                Node *tempNode = getPredeccor(node->left);
                node->data = tempNode->data;
                node->left = removeNode(tempNode->data, node->left);
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

trees tri;
int n,elem,m,delem;
cout << "Enter the number of elements in a Tree..:" << endl;
cin >> n;
for(int i=0; i<n; i++)
{
    cin>> elem;
    tri.insert(elem);

}
tri.display();
cout << "Enter the number of elements to delete.." << endl;
cin >> m;
for(int i=0; i<m; i++)
{
    cin >> delem;
    tri.remove(delem);
    cout << "Tree After deletion.." << endl;
    tri.display();
    cout << endl;
}


    return 0;
}