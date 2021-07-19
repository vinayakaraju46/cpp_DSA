#include<bits/stdc++.h>

using namespace std;

void display(vector<int> arr)
{
    for(int j=0; j<arr.size();j++)
    {
        cout << arr[j] << " ";
    }
    cout << endl;
}


int main()
{
    
    int N,K,elem,T;
    cin >> T;
    for(int i=0; i<T; i++)
    {   vector<int> arr;
        vector<int>:: iterator it;
        cin >> N;
        cin >> K;
        for(int j=0; j<N; j++)
        {   cin >> elem;
            it = find(arr.begin(),arr.end(),elem);
            if(it==arr.end())
            {
                arr.push_back(elem);
            }
        }
        if(arr.size() < K)
        {
            cout << "Bad" << endl;
        }
        if(arr.size() == K)
        {
            cout << "Good" << endl;
        }
        if(arr.size() > K)
        {
            cout << "Average" << endl;
        }
        arr.clear();

    }







    return 0;
}