#include<bits/stdc++.h>

using namespace std;

struct node
{
    public:
        int data;
        struct node *left;
        struct node *right;
        int ht;
    node(const int &val)
    {
        data = val;
        left = NULL;
        right = NULL;
        ht = 0;
    }    
};

struct AvlTree
{
    public:
        struct node *root;
        int size;
        AvlTree()
        {
            root = NULL;
            size = 0;
        }

        int calheight(struct node *nodee)
        {
            if(nodee == NULL)
            {
                return -1;
            }
            return nodee->ht;
        }

        int calcBalance(struct node *nodee)
        {
            if(nodee == NULL)
            {
                return 0;
            }
            return (calheight(nodee->left) - calheight(nodee->right));
        }





        AvlTree &insert(const int &val)
        {
            root = insertNode(val,root);
        }

        node *insertNode(const int &val,node *nodee)
        {
            if (nodee == NULL)
            {
                return new node(val);
            }
            else if(val < nodee->data)
            {
                nodee->left = insertNode(val, nodee->left);
            }
            else if(val > nodee->data)
            {
                nodee->right = insertNode(val, nodee->right);
            }
            return SettleViolation(val,nodee);
        }

        node * SettleViolation(const int &val,struct node * nodee)
        {
            int balance = calcBalance(nodee);
            
            if(balance > 1 && val < nodee->left->data)
            {
                return rotateright(nodee);
            }
            else if(balance > 1 && val > nodee->left->data)
            {
                nodee->left = rotateleft(nodee->left);
                return rotateright(nodee);
            }
            else if(balance < -1 && val > nodee->right->data)
            {
                return rotateleft(nodee);
            }
            else if(balance < -1 && val < nodee->right->data)
            {
                nodee->right = rotateright(nodee->right);
                return rotateleft(nodee);
            }
            return nodee;
        }




        node * rotateright(struct node *nodee)
        {
            struct node *templeftchild = nodee->left;
            struct node *t = templeftchild->right;

            templeftchild->right = nodee;
            nodee->left = t;

            nodee->ht = max(calheight(nodee->left),calheight(nodee->right)) + 1;
            templeftchild->ht = max(calheight(templeftchild->left),calheight(templeftchild->right)) + 1;
            return templeftchild;
        }

        node * rotateleft(struct node *nodee)
        {
            struct node *temprightchild = nodee->right;
            struct node *t = temprightchild->left;

            temprightchild->left = nodee;
            nodee->right = t;

            nodee->ht = max(calheight(nodee->left),calheight(nodee->right)) + 1;
            temprightchild->ht = max(calheight(temprightchild->left),calheight(temprightchild->right)) + 1;
            return temprightchild;
        }




        void display()
        {
            traverseinorder(root);
        }

        void traverseinorder(struct node *nodee)
        {
            if(nodee->left)
            {
                traverseinorder(nodee->left);
            }
            cout << nodee->data << endl;
            if(nodee->right)
            {
                traverseinorder(nodee->right);
            }
        }

        
};







int main()
{

AvlTree avl;
int n,elem;
cout << "Enter the number of elements in an array.." << endl;
cin >> n;
for(int i=0; i<n; i++)
{
    cin >> elem;
    avl.insert(elem);
}
avl.display();




    return 0;
}