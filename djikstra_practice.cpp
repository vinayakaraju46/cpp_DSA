#include<bits/stdc++.h>

using namespace std;

class Edge;

class Node
{
    public:
        int min_distance;
        string name;
        bool visited;
        vector<Edge *> adjacencylist;
        Node *predeccor;
        Node(string data)
        {
            name = data;
            visited = false;
            predeccor = NULL;
            min_distance = INT_MAX;
        }
};

class Edge
{
    public:
        Node *startNode;
        Node *targetNode;
        int weight;
        Edge(int wgt,Node *start,Node *tar)
        {
            weight = wgt;
            startNode = start;
            targetNode = tar;
        }
};

class Algorithm
{
    public:
        priority_queue< pair<int,Node*> > que;
        void calculateshortestpath(Node *Node_arr[], Node *startvertex)
        {
            startvertex->min_distance = 0;
            que.push(pair< int, Node*>(startvertex->min_distance,startvertex));
            while(que.size() != 0)
            {
                pair<int,Node*> temp = que.top();
                Node *tempNode = temp.second;
                que.pop();
                for(int i=0; i<tempNode->adjacencylist.size();i++)
                {
                    Node *u = tempNode->adjacencylist[i]->startNode;
                    Node *v = tempNode->adjacencylist[i]->targetNode;
                    int newdist = u->min_distance + tempNode->adjacencylist[i]->weight;
                    if(newdist < v->min_distance)
                    {
                        v->predeccor = u;
                        v->min_distance = newdist;
                        que.push(pair<int,Node*>(v->min_distance,v));
                    }
                }
            }
        }

        void getshortestpath(Node *tarverser)
        {
            cout << "Shortest path is ...!" << tarverser->min_distance<< endl;
            Node *curr = tarverser;
            while(curr)
            {
                cout << curr->name << endl;
                curr = curr->predeccor;
            }
        }





};



int main()
{







    return 0;
}