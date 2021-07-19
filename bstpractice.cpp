#include<bits/stdc++.h>

using namespace std;

class Node 
{
    public:
        int data;
        Node *leftChild;
        Node *rightChild;

        Node(const int &val) 
        {
            data = val;
            leftChild = NULL;
            rightChild = NULL;
        }
};

class BinarySearchTree 
{
    public:
        Node *root;

        BinarySearchTree() {
            root = NULL;
        }

        Node *insert(const int &val) {
            root = insertNode(val, root);
            return root;
        }

        Node *insertNode(const int &val, Node *node) {
            if(node == NULL) {
                return new Node(val);
            } else if(val < node->data) {
                node->leftChild = insertNode(val, node->leftChild);
            } else if(val > node->data) {
                node->rightChild = insertNode(val, node->rightChild);
            }
            return node;
        }

        Node *remove(const int &val) {
            root = removeNode(val, root);
            return root;
        }

        Node *removeNode(const int &val, Node *node) {
            if(node == NULL) {
                return NULL;
            } else if(val < node->data) {
                node->leftChild = removeNode(val, node->leftChild);
            } else if(val > node->data) {
                node->rightChild = removeNode(val, node->rightChild);
            } else {
                if(node->leftChild == NULL && node->rightChild == NULL) {
                    cout << "Removing leaf node" << endl;
                    delete node;
                    return NULL;
                } else if(node->leftChild == NULL && node->rightChild != NULL) {
                    cout << "Removing the node with one right child" << endl;
                    Node *tempNode = node->rightChild;
                    delete node;
                    return tempNode;
                } else if(node->leftChild != NULL && node->rightChild == NULL) {
                    cout << "Removing the node with one Left child" << endl;
                    Node *tempNode = node->leftChild;
                    delete node;
                    return tempNode;
                } else {
                    cout << "Removing the node with two children" << endl;
                    Node *tempNode = getPredeccor(node->leftChild);
                    node->data = tempNode->data;
                    node->leftChild = removeNode(tempNode->data, node->leftChild);
                }
            }
            return node;
        }

        Node *search(Node *node, const int &val) {
            Node *searchnode = searchNode(node, val);
            cout << searchnode->data << endl;
            return searchnode;
        }

        Node *searchNode(Node *node, const int &val) {
             if(val < node->data) {
                searchNode(node->leftChild, val);
            } else if(val > node->data) {
                searchNode(node->rightChild, val);
            }else if(val == node->data || node == NULL) {
                cout << node->data << "Found" << endl;
                return node;
            }
        }

        Node *getPredeccor(Node *node) {
            if(node->rightChild) {
                return getPredeccor(node->rightChild);
            }
            return node;
        }

        void traverse(Node *node) {
            traverseinorder(node);
        }

        void traverseinorder(Node *node) {
            if(node->leftChild) {
                traverseinorder(node->leftChild);
            }
            cout << node->data << " ";
            if(node->rightChild) {
                traverseinorder(node->rightChild);
            }
        }
};

int main() {

    int n, elem, d, delem;
    BinarySearchTree bst;
    cout << "Enter the number of elements in a Tree" << endl;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> elem;
        bst.insert(elem);
    }
    // cout << "Tree is : " << endl;
    // bst.traverse();
    
    cout << "Enter the node to search" << endl;
    cin >> d;
    Node *root = bst.root;
    Node *node = bst.searchNode(root, d);
    bst.traverse(node);


    return 0;
}