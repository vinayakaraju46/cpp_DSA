#include<bits/stdc++.h>

using namespace std;

class Node {
    public:
        char character;
        Node *left; 
        Node *right;
        Node *middle;
        int value;

        Node(char c) {
            character = c;
            left = NULL;
            right = NULL;
            middle = NULL;
            value = 0;
        }
};

class TernarySearchTree {
    public:
        Node *root;

        TernarySearchTree() {
            root = NULL;
        }

        Node *insert(string key, const int &val) {
            root = insertNode(key, val, root, 0);
        }

        Node *insertNode(string key, const int &val, Node *node, int index) {
            char c = key[index];
            if(node == NULL) {
                node = new Node(c);
            } 
            if(c < node->character) {
                node->left = insertNode(key, val, node->left, index);
            } else if(c > node->character) {
                node->right = insertNode(key, val, node->right, index);
            } else if(index < key.length() - 1) {
                node->middle = insertNode(key, val, node->middle, index + 1);
            } else {
                node->value = val;
            }
            return node;
        }

        int getval(string key) {
            Node *node = getValueFromTree(root, key, 0);
            if(node == NULL) {
                return -1;
            }
            return node->value;
        }

        Node *getValueFromTree(Node *node, string key, int index) {
            if(node == NULL) {
                return NULL;
            }
            char c = key[index];
            if(c < node->character) {
                return getValueFromTree(node->left, key, index);
            } else if(c > node->character) {
                return getValueFromTree(node->right, key, index);
            } else if(index < key.length() - 1) {
                return getValueFromTree(node->middle, key, index + 1);
            } else {
                return node;
            }
        }
};

int main() {
TernarySearchTree tt;
string sttr,getsttr;
int value;
int n;
cout << "Enter the number of key value pairs.." << endl;
cin >> n;
for(int i=0; i<n;i++)
{
    cin >> sttr;
    cin >> value;
    tt.insert(sttr,value);
}

cout << "Enter the retrieval key.." << endl;
cin >> getsttr;
int x;
x = tt.getval(getsttr);
cout << x;


    return 0;
}