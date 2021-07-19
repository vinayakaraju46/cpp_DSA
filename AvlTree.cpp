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

class Tree
{
    public:
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
            node->height = max(CalcHeight(node->left),CalcHeight(node->right)) + 1;
            return SettleViolations(val, node);
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
            else if(bal < -1 && val < node->right->data)
            {
                node->right = rotateright(node->right);
                return rotateleft(node);
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

            node->height = max(CalcHeight(node->left), CalcHeight(node->right)) + 1;
            temprightchild->height = max(CalcHeight(temprightchild->left), CalcHeight(temprightchild->right)) + 1;
            return temprightchild;
        }

        void BreadthFirstSearch()
        {
            queue<Node *> que;
            que.push(root);

            while(que.size() != 0)
            {
                Node *tempNode = que.front();
                que.pop();
                cout << tempNode->data << " ";
                if(tempNode->left)
                {
                    que.push(tempNode->left);
                }
                if(tempNode->right)
                {
                    que.push(tempNode->right);
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
    cout << "Enter the number of elements in a Tree : " << endl;
    cin >> n;
    Tree tr;

    for(int i=0; i<n; i++)
    {
        cin >> elem;
        tr.insert(elem);
    }
    tr.display();
    cout << endl;
    cout << "BreadthFirst Search.." << endl;
    tr.BreadthFirstSearch();




    return 0;
}