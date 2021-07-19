#include<iostream>

using namespace std;

template<class T>
class Node
{
    public:
    T data;
    Node<T> *left;
    Node<T> *right;
    int height;
    Node(const T &val)
    {
        data = val;
        left = NULL;
        right = NULL;
        height = 0;
    }
};

template<class T>
class AvlTre
{
    public:
    Node<T> *root;
    int size;
    AvlTre()
    {
        root = NULL;
        size = 0;
    }

    int CalcHeight(Node<T> *node)
    {
        if(node == NULL)
            return -1;
        return node->height;
    }

    int CalcBalance(Node<T> *node)
    {
        if(node == NULL)
        {
            return 0;
        }
        else
        {
            return CalcHeight(node->left) - CalcHeight(node->right);
        }

    }

    AvlTre<T> &insert(const T &val)
    {   
        size = size + 1;
        root = insertNode(val, root);
    }

    Node<T> *insertNode(const T &val, Node<T> *node)
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

        node->height = max(CalcHeight(node->left),CalcHeight(node->right)) + 1;
        return SettleViolation(val, node);

    }



    AvlTre<T> &remove(const T &val)
    {
        root = removeNode(val, root);
    }

    Node<T> *removeNode(const T &val, Node<T> *node)
    {   Node<T> *tempNode = NULL;
        if(node == NULL)
        {
            return NULL;
        }
        else if (val < node->data)
        {
            node->left = removeNode(val, node->left);
        }
        else if (val > node->data)
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
            else if(node->left != NULL && node->right == NULL)
            { 
                tempNode = node->left;
                delete node;
                return tempNode;
            }
            else if(node->left == NULL && node->right != NULL)
            {   
                tempNode = node->right;
                delete node;
                return tempNode;
            }
            else
            {
                tempNode = getPredeccor(node->left);
                node->data = tempNode->data;
                node->left = removeNode(tempNode->data,node->left);
            }
            
            
        }
        if(node == NULL)
        {
            return node;
        }
        node->height = max(CalcHeight(node->left),CalcHeight(node->right)) + 1;

        int balance = CalcBalance(node);

        if(balance > 1 && CalcBalance(node->left) >= 0)
        {
            return rotateright(node);
        }
        else if(balance > 1 && CalcBalance(node->left) < 0)
        {
            node->left = rotateright(node->left);
            return rotateright(node);
        }
        else if(balance < -1 && CalcBalance(node->right) <= 0)
        {
            return rotateleft(node);
        }
        else if(balance < -1 && CalcBalance(node->right) > 0)
        {
            node->right = rotateright(node->right);
            return rotateleft(node);
        }
        return node;
        
    }


    Node<T> *getPredeccor(Node<T> *node)
    {
        if(node->right)
        {
            return getPredeccor(node->right);
        }
        return node;
    }


    Node<T> *SettleViolation(const T &val, Node<T> *node)
    {
        int balance = CalcBalance(node);

        if(balance > 1 && val < node->data)
        {
            return rotateright(node);
        }
        else if (balance > 1 && val > node->data)
        {
            node->left = rotateleft(node->left);
            return rotateright(node);
        }
        else if (balance < -1 && val > node->data)
        {
            return rotateleft(node);
        }
        else if(balance < -1 && val < node->data)
        {
            node->right = rotateright(node->right);
            return rotateleft(node);
        }
        return node;
    }


    Node<T> *rotateleft(Node<T> *node)
    {   Node<T> *temprightchild = node->right;
        Node<T> *t = temprightchild->left;

        temprightchild->left = node;
        node->right = t;

        node->height = max(CalcHeight(node->left),CalcHeight(node->right)) + 1;

        temprightchild->height = max(CalcHeight(temprightchild->left),CalcHeight(temprightchild->right)) + 1;
        return temprightchild;
    }

    Node<T> *rotateright(Node<T> *node)
    {   Node<T> *templeftchild = node->left;
        Node<T> *t = templeftchild->right;

        templeftchild->right = node;
        node->left = t;

        node->height = max(CalcHeight(node->left),CalcHeight(node->right)) + 1;

        templeftchild->height = max(CalcHeight(templeftchild->left),CalcHeight(templeftchild->right)) + 1;
        return templeftchild;
    }

    void searchoperation(const int &val)
    {  
        searchval(root,val);
        
    }

    void searchval(Node<T> *node,const int &val)
    {
        if(node == NULL)
        {
            cout << "Not found..";
        }
        else if(val < node->data)
        {
            searchval(node->left,val);
        }
        else if(val == node->data)
        {
            cout << "Found.." << endl;
        }
        else if(val > node->data)
        {
            searchval(node->right,val);
        }
        
    }

    




    int sizeofthem()
    {
        return size;
    }

    void traverse()
    {
        traverseinorder(root);
    }
    void traverseinorder(Node<T> *node)
    {
        if(node->left)
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
AvlTre<int> avl;
int n,elem,fin;
string st;
cin >> n;
for(int i=0; i<n; i++)
{
    // cin >> st;
    cin >> elem;
    avl.insert(elem);
    
}
avl.traverse();
cout << "Enter the val to find in a tree.." << endl;
cin >> fin;
avl.searchoperation(fin) ;




    return 0;
}