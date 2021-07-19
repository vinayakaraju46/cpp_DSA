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

class Avl
{
    public:
        Node *root;

        Avl()
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
            return settleViolations(val, node);
        }

        Node *settleViolations(const int  &val, Node *node)
        {
            int balance = CalcBalance(node);

            if(balance > 1 && val < node->left->data)
            {
                return rotateright(node);
            }
            else if(balance > 1 && val > node->left->data)
            {
                node->left = rotateleft(node->left);
                return rotateright(node);
            }
            else if(balance < -1 && val > node->right->data)
            {
                return rotateleft(node);
            }
            else if(balance < -1 && val < node->right->data)
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
                    cout << "Removing the leaf node." << endl;
                    delete node;
                    return NULL;
                }
                else if(node->left == NULL && node->right != NULL)
                {
                    cout << "Removing the node with one rightchild .." << endl;
                    Node *tempNode = node->right;
                    delete node;
                    return tempNode;
                }
                else if(node->left != NULL && node->right == NULL)
                {
                    cout << "Removing the node with one leftchild.." << endl;
                    Node *tempNode = node->left;
                    delete node;
                    return tempNode;
                }
                cout << "Removing the node with two children.." << endl;
                Node *tempNode = getPredeccor(node->left);
                node->data = tempNode->data;
                node->left = removeNode(tempNode->data, node->left);
            }

            if(node == NULL)
            {
                return node;
            }

            node->height = max(CalcHeight(node->left), CalcHeight(node->right)) + 1;

            int balance = CalcBalance(node);
            if(balance > 1 && CalcBalance(node->left) >= 0)
            {
                return rotateright(node);
            }
            else if(balance > 1 && CalcBalance(node->left) < 0)
            {
                node->left = rotateleft(node->left);
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

        Node *getPredeccor(Node *node)
        {
            if(node->right)
            {
                return getPredeccor(node->right);
            }
            return node;
        }




        Node *rotateleft(Node *node)
        {
            Node *temprightchild = node->right;
            Node *t = temprightchild->left;

            temprightchild->left = node;
            node->right = t;
            node->height = max(CalcHeight(node->left), CalcHeight(node->right)) + 1;
            temprightchild->height = max(CalcHeight(temprightchild->left), CalcHeight(temprightchild->right)) + 1;
            return temprightchild;
        }

        Node *rotateright(Node *node)
        {
            Node *templeftchild = node->left;
            Node *t = templeftchild->right;
            templeftchild->right = node;
            node->left = t;
            node->height = max(CalcHeight(node->left) , CalcHeight(node->right)) + 1;
            templeftchild->height = max(CalcHeight(templeftchild->left) , CalcHeight(templeftchild->right)) + 1;
            return templeftchild;
        }


        void BreadthFirstSearch()
        {
                queue<Node *> que;
                que.push(root);


                while(que.size()!=0)
                {
                    Node *temp = que.front();
                    cout << temp->data << endl;
                    que.pop();
                    if(temp->left)
                    {
                        que.push(temp->left);
                    }
                    if(temp->right)
                    {
                        que.push(temp->right);
                    }
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
int n,elem;
Avl av;
cout << "Enter the number of elements to insert to a tree.." << endl;
cin >> n;
for(int i=0; i<n; i++)
{
    cin >> elem ;
    av.insert(elem);
}
// av.traverseinorder(av.root);
av.BreadthFirstSearch();
int d,delem;
cin >> d;
for(int i=0; i<d; i++)
{
    cin >> delem;
    av.remove(delem);
    cout << endl;
    cout << "Tree after deleting.." << endl;
    // av.display();
    av.BreadthFirstSearch();
}






    return 0;

}