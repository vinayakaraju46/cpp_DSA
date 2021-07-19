#include<bits/stdc++.h>


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

class Trees
{
    public:
        Node *root;

        Trees()
        {
            root = NULL;
        }

        int CalcHeight(Node *node)
        {
            if(node == NULL)
            {
                return -1;
            }
            return node->height;
        }

        int CalcBalance(Node *node)
        {
            if(node == NULL)
            {
                return 0;
            }
            return CalcHeight(node->left) - CalcHeight(node->right);
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
            else if(val < node->data)
            {
                node->left = insertNode(val, node->left);
            }
            else if(val > node->data)
            {
                node->right = insertNode(val, node->right);
            }
            node->height = max(CalcHeight(node->left), CalcHeight(node->right)) + 1;
            return SettleViolations(val,node);
        }

        Node *SettleViolations(const int &val, Node *node)
        {
            int bal = CalcBalance(node);

            if(bal > 1 && val < node->left->data)
            {
                return rotateright(node);
            }
            else if(bal > 1 && val > node->left->data)
            {
                node->left = rotateleft(node->left);
                return rotateright(node);
            }
            else if(bal < -1 && val > node->right->data)
            {
                return rotateleft(node);
            }
            else if (bal < -1 && val < node->right->data)
            {
                node->right = rotateright(node->right);
                return rotateleft(node);
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
                    delete(node);
                    return NULL;
                }
                else if(node->left == NULL && node->right != NULL)
                {
                    Node *tempNode = node->right;
                    delete node;
                    return tempNode;
                }
                else if(node->left != NULL && node->right == NULL)
                {
                    Node *tempNode = node->left;
                    delete node;
                    return tempNode;
                }
                Node *tempNode = getPredeccor(node->left);
                node->data = tempNode->data;
                node->left = removeNode(tempNode->data, node->left);
            }
            if(node == NULL)
            {
                return NULL;
            }
            node->height = max(CalcHeight(node->left),CalcHeight(node->right)) + 1;

            int bal = CalcBalance(node);
            if(bal > 1 && CalcBalance(node->left) < 0)
            {
                return rotateright(node);
            }
            else if(bal > 1 && CalcBalance(node->left) >= 0)
            {
                node->left = rotateleft(node->left);
                return rotateright(node);
            }
            else if(bal < -1 && CalcBalance(node->right) >= 0)
            {
                return rotateleft(node);
            }
            else if(bal < -1 && CalcBalance(node->left) < 0)
            {
                node->right = rotateright(node->right);
                return rotateleft(node);
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






        Node *rotateright(Node *node)
        {
            Node *tempLeftchild = node->left;
            Node *t = tempLeftchild->right;

            tempLeftchild->right = node;
            node->left = t;

            node->height = max(CalcHeight(node->left),CalcHeight(node->right)) + 1;
            tempLeftchild->height = max(CalcHeight(tempLeftchild->left),CalcHeight(tempLeftchild->right)) + 1;
            return tempLeftchild;
        }

        Node *rotateleft(Node *node)
        {
            Node *temprightchild = node->right;
            Node *t = temprightchild->left;

            temprightchild->left = node;
            node->right = t;

            node->height = max(CalcHeight(node->left),CalcHeight(node->right) ) + 1;
            temprightchild->height = max(CalcHeight(temprightchild->left),CalcHeight(temprightchild->right)) + 1;
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
Trees tr;
int n,elem;
cout << "Enter the number of Elements in a Tree.." << endl;
cin >> n;
for(int i=0; i<n; i++)
{
    cin >> elem;
    tr.insert(elem);
}
tr.display();
cout << endl;
cout << "Enter the number of elements to delete from a tree.." << endl;
int m,delem;
cin >> m;
for(int i=0; i<m; i++)
{
    cin >> delem;
    tr.remove(delem);
}
tr.display();



    return 0;
}