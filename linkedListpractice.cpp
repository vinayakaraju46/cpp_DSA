#include<iostream>


using namespace std;

class Node
{
    public:
        int data;
        Node *left;
        Node *right;
        int height;

        Node(const int &val)
        {
            data = val;
            left = NULL;
            right = NULL;
            height = 0;
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

        int calcHeight(Node *node)
        {
            if(node == NULL)
            {
                return -1;
            }
            return node->height;
        }

        int calcbalance(Node *node)
        {
            if(node == NULL)
            {
                return 0;
            }
            return (calcHeight(node->left) - calcHeight(node->right));
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

            if(val < node->data)
            {
                node->left = insertNode(val ,node->left);
            }
            if(val > node->data)
            {
                node->right = insertNode(val ,node->right);
            }
            node->height = max(calcHeight(node->left),calcHeight(node->right)) + 1;
            return settleviolations(node,val);

        }

        Node *settleviolations(Node *node,const int &val)
        {
            int bal = calcbalance(node);

            if(bal > 1 && val < node->left->data)
            {
                return rotateright(node);
            }
            if(bal > 1 && val > node->left->data)
            {
                node->left = rotateleft(node->left);
                return rotateright(node);
            }
            if(bal < -1 && val > node->right->data)
            {
                return rotateleft(node);
            }
            if(bal < -1 && val < node->right->data)
            {
                node->right = rotateright(node->right);
                return rotateleft(node);
            }
            return node;
        }

        Node *rotateright(Node *node)
        {
            Node *templeftchild = node->left;
            Node *t = templeftchild->right;
            
            templeftchild->right = node;
            node->left = t;

            node->height = max(calcHeight(node->left),calcHeight(node->right)) + 1;
            templeftchild->height = max(calcHeight(templeftchild->left),calcHeight(templeftchild->right)) + 1;
            return templeftchild;
        }

        Node *rotateleft(Node *node)
        {
            Node *temprightchild = node->right;
            Node *t = temprightchild->left;

            temprightchild->left = node;
            node->right = t;

            node->height = max(calcHeight(node->left),calcHeight(node->right)) + 1;
            temprightchild->height = max(calcHeight(temprightchild->left),calcHeight(temprightchild->right)) + 1;
            return temprightchild;
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
for(int i=0; i<n ; i++)
{
    cin >> elem;
    tr.insert(elem);
}
tr.display();



    return 0;
}