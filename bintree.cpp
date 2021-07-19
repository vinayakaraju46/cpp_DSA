#include<iostream>

using namespace std;

template<class T>
class Node
{
    public:
    T data;
    Node<T> *left;
    Node<T> *right;
    Node(const T &val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }

};


template<class T>
class BinTree
{
    public:
    Node<T> *root;
    int size;
    BinTree()
    {
        root = NULL;
        size = 0;
    }

    BinTree<T> &insert(const T &val)
    {
        root = insertNode(val,root);
        return *this;
    }

    Node<T> *insertNode(const T &val, Node<T> *node)
    {
        if (node == NULL)
        {
            return new Node<T>(val);
        }
        else if( val < node->data)
        {
            node->left = insertNode(val, node->left); 
        }
        else if(val > node->data)
        {
            node->right = insertNode(val, node->right);
        }
        return node;
    }


    BinTree<T> &remove(const T &val)
    {
        root = removeNode(val,root);
    }

    Node<T> *removeNode(const T &val, Node<T> *node)
    {   Node<T> *tempNode = NULL;

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
                cout << "Deleting a Leaf Node" << endl;
                delete node;
                return NULL;
            }
            else if(node->left == NULL && node->right != NULL)
            {   cout << "Deleting the node with one right child.." << endl;
                tempNode = node->right;
                delete node;
                return tempNode;
            }
            else if(node->left != NULL && node->right == NULL)
            {
                cout << "Deleting the node with one leftchild.." << endl;
                tempNode = node->left;
                delete node;
                return tempNode;
            }
            else
            {
                cout << "Deleting the node with two children.." << endl;
                tempNode = getPredeccor(node->left);
                node->data = tempNode->data;
                node->left = removeNode(tempNode->data, node->left);
            }
            return node;
            
        }
        

    }

    Node<T> *getPredeccor(Node<T> *node)
    {
        if(node->right)
        {
          return getPredeccor(node->right);
        }
        return node;
    }
    

    void traverse()
    {
        traverseinorder(root);
    }
    void traverseinorder(Node<T> *node)
    {
        if ( node->left )
        {
            traverseinorder(node->left);
        }
        cout << node->data << endl;

        if(node->right)
        {
            traverseinorder(node->right);
        }
    }


};




int main()
{
int n,elem,n1;
BinTree<int> Tree;
cout << "Enter the number of elements in a tree.." << endl;
cin >> n;
for(int i=0; i<n; i++)
{
    cin >> elem;
    Tree.insert(elem);
}
cout << "Tree is.." << endl;
Tree.traverse();
cout << "Enter the element to be deleted.." << endl;
cin >> n1;
Tree.remove(n1);
Tree.traverse();


    return 0;
}