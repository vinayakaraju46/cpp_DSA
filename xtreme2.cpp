#include <bits/stdc++.h> 
using namespace std; 

vector<int *> master;


void findcombi(vector<int> arr, int index, int num,int reducedNum, int a,int b)
{
    if(reducedNum < 0)
    {
        return;
    }

    if(reducedNum == 0)
    {
        master.push_back(arr);
        for(int i=0; i<index; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
        return ;
    }
    
}