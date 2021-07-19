#include<bits/stdc++.h>


using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        int height;

        Node(const int &val) {
            data = val;
            left = NULL;
            right = NULL;
            height = 0;
        }
};

class AvlTrees {
    public:
        Node *root;

        AvlTrees() {
            root = NULL;
        }

        int calcHeight(Node *node) {
            if(node == NULL) {
                return -1;
            }
            return node->height;
        }

        int calcBalance(Node *node) {
            if(node == NULL) {
                return 0;
            }
            return calcHeight(node->left) - calcHeight(node->right);
        }

        Node *insert(const int &val) {
            root = insertNode(val, root);
        }

        Node *insertNode(const int &val, Node *node) {
            if(node == NULL) {
                return new Node(val);
            } else if(val < node->data) {
                node->left = insertNode(val, node->left);
            } else if (val > node->data) {
                node->right = insertNode(val, node->right);
            }
            node->height = max(calcHeight(node->left), calcHeight(node->right)) + 1;
            return settleViolations(val, node);
        }

        Node *settleViolations(const int &val, Node *node) {
            int balance = calcBalance(node);

            if(balance > 1 && val < node->left->data) {
                return rotateRight(node);
            } else if(balance > 1 && val > node->left->data) {
                node->left = rotateLeft(node->left);
                return rotateRight(node);
            } else if(balance < -1 && val > node->right->data) {
                return rotateLeft(node);
            } else if(balance < -1 && val < node->right->data) {
                node->right = rotateRight(node->right);
                return rotateLeft(node);
            }
            return node;
        }

        Node *rotateRight(Node *node) {
            Node *tempLeftChild = node->left;
            Node *t = tempLeftChild->right;

            tempLeftChild->right = node;
            node->left = t;
            node->height = max(calcHeight(node->left), calcHeight(node->right)) + 1;
            tempLeftChild->height = max(calcHeight(tempLeftChild->left), calcHeight(tempLeftChild->right)) + 1;
            return tempLeftChild;
        }

        Node *rotateLeft(Node *node) {
            Node *tempRightChild = node->right;
            Node *t = tempRightChild->left;

            tempRightChild->left = node;
            node->right = t;
            node->height = max(calcHeight(node->left), calcHeight(node->right)) + 1;
            tempRightChild->height = max(calcHeight(tempRightChild->left), calcHeight(tempRightChild->right)) + 1;
            return tempRightChild; 
        }

        void display() {
            traverseinorder(root);
        }

        void traverseinorder(Node *node) {
            if(node->left) {
                traverseinorder(node->left);
            }
            cout << node->data << " ";
            if(node->right) {
                traverseinorder(node->right);
            }

        }
};


int main() {
    int n,elem;
    AvlTrees avl;
    cout << "Enter the number of elements in Tree" << endl;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> elem;
        avl.insert(elem);
    }
    cout << "Your Avl Tree is: " << endl;
    avl.display();




    return 0;
}