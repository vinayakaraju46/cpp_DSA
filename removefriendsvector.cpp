#include<bits/stdc++.h>

using namespace std;

void display(vector<int> arr)
{
    for(int i=0; i<arr.size();i++)
    {
        cout << arr[i] << " ";
    }
}




int main()
{   vector<int> arr;
vector<int>::iterator it;
    int T,elem;
    long int N,K;
    cin >> T;
    for(int i=0;i<T;i++)
    {
        cin >> N;
        cin >> K;
        for(int j=0;j<N;j++)
        {   
            cin >> elem;
            arr.push_back(elem);
        }
        for(int k=0; k<K; k++)
        {
            for(int l=0; l<arr.size();l++)
            {
                if(arr[l] < arr[l+1])
                    arr.erase(std::find(arr.begin(),arr.end(),arr[l]));
            }
        }
        display(arr);
        arr.clear();
        // display(arr);
        cout << endl;
    
        
    }
}