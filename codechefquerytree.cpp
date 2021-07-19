#include <iostream>
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
class Binarytree
{
    public:
        Node<T> *root;
        int size;
        Binarytree()
        {
            root = NULL;
            size = 0;
        }
        
         Node<T> *insertNode(const T &val,Node<T> *node)
        {
            if(node == NULL)
            {
                return new Node<T>(val);
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
        
        Binarytree<T> &insert(const T &val)
        {
            root = insertNode(val,root);
        }
        
       
        
        Binarytree<T> &remove(const T &val)
        {
            root = removeNode(val, root);
        }
        
        Node<T> *removeNode(const T &val,Node<T> *node)
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
                    delete node;
                    return NULL;
                }
                else if(node->left == NULL && node->right != NULL)
                {
                    tempNode = node->right;
                    delete node;
                    return tempNode;
                }
                else if(node->left != NULL && node->right == NULL)
                {
                    tempNode = node->left;
                    delete node;
                    return tempNode;
                }
                else
                {
                 tempNode = getPredeccor(node->left);
                 node->data = tempNode->data;
                 node->left = removeNode(tempNode->data,node->left);
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

        void display()
        {
            traverseinorder(root);
        }

        void traverseinorder(Node<T> *node)
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
{   Binarytree<int> bin;
    int q,elem;
    char i;
    cin >> q;
    for(int j=0;j<q; j++)
    {
        cin >> i;
        cin >> elem;
        if( i == 'i')
        {
            bin.insert(elem);
        }
        if( i == 'd')
        {
            bin.remove(elem);
        }
        
    }
    bin.display();
    
    
    
	return 0;
}