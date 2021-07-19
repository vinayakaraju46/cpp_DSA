#include<bits/stdc++.h>


using namespace std;

class Node
{
    public:
        int data;
        Node* next;
        Node(const int &val)
        {
            data = val;
            next = NULL;
        }
};

class BinNode
{
    public:
        int data;
        BinNode *left;
        BinNode *right;
        BinNode(const int &val)
        {
            data = val;
            left = NULL;
            right = NULL;
        }
};


class Tree
{
    public:
        BinNode *root;
        int h;
        Tree()
        {
            root = NULL;
        }

        int calcHeight(BinNode *node)
        {
            if(node == NULL)
            {
                return 0;
            }
            return (max(calcHeight(node->left),calcHeight(node->right)))+1;
        }

        int calcBalance(BinNode *node)
        {
            if(node == NULL)
            {
                return 1;
            }
            return calcHeight(node->left) - calcHeight(node->right);
        }

        Tree &insert(const int &val)
        {
            root = insertNode(val,root);
        }

        BinNode *insertNode(const int &val, BinNode *node)
        {
            if(node == NULL)
            {
                return new BinNode(val);
            }
            if(val < node->data)
            {
                node->left = insertNode(val, node->left);
            }
            if(val > node->data)
            {
                node->right = insertNode(val,node->right);
            }
            return settleViolations(val,node);
        }

        BinNode *settleViolations(const int val,BinNode *node)
        {
            int balance = calcBalance(node);
            if(balance > 1 && val < node->data)
            {
                cout << "Left Left heavy situation.." << endl;
                return rotateright(node);
            }
            if(balance > 1 && val > node->data)
            {
                cout << "Left Right heavy situation.." << endl;
                node->left = rotateleft(node->left);
                return rotateright(node);
            }
            if(balance < -1 && val > node->data)
            {
                cout << "Right Right heavy situation.." << endl;
                return rotateleft(node);
            }
            if(balance < -1 && val < node->data)
            {
                cout << "Right Left heavy situation.." << endl;
                node->right = rotateright(node);
                return rotateleft(node);
            }
            return node;
        }

        BinNode* rotateright(BinNode *node)
        {
            BinNode *tempLeftchild = node->left;
            BinNode *t = tempLeftchild->right;
            tempLeftchild->right = node;
            node->left = t;
            
            return tempLeftchild;

        }
        BinNode* rotateleft(BinNode *node)
        {
            BinNode *temprightchild = node->right;
            BinNode *t = temprightchild->left;
            temprightchild->right = node;
            node->right = t;
            return temprightchild;
        }

        void display()
        {
            traverseinorder(root);
        }

        void traverseinorder(BinNode *node)
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
Tree bin;
int n,elem;
cin >> n;
for(int i=0; i<n; i++)
{
    cin >> elem;
    bin.insert(elem);
}
bin.display();


    return 0;
}