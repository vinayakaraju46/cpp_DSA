#include<bits/stdc++.h>


using namespace std;

void printarr(vector<int> arr)
{
    for(int i=0; i<arr.size();i++)
    {
        cout << arr[i] << endl;
    }
}

void medianvec(vector<int> arr)
{   if(arr.size() == 0)
    {
        cout << "Wrong!" << endl;
    }
    
    if(arr.size() == 1)
    {
        cout << arr[0] << endl;
    }
    if(arr.size() == 2)
    {   float result = arr[0] + arr[1];

        cout << result/2 << endl;
    }
    if(arr.size() > 2)
    {
        if(arr.size()%2 == 0)
        {
            int temp = int(arr.size()-1)/2;
            float result = arr[temp] + arr[temp+1];
            cout << result/2 << endl;
        }
        else
        {
            int temp = int(arr.size()-1)/2;
            cout << arr[temp] << endl;
        }
        
    }
    
}




int main()
{
    vector<int> arr;
    vector<int>:: iterator it;
    string st;
    int N,elem;
    cin >> N;
    for(int i=0; i<N;++i)
    {
        cin >> st;
        cin >> elem;
        if(st == "r")
        {   it = find(arr.begin(),arr.end(),elem);

            if(it == arr.end() && arr.size() == 0)
            {
                cout << "Wrong!" << endl;
            }
            else
            {
                arr.erase(std::find(arr.begin(),arr.end(),elem));
            }
            
        }
        else if(st == "a")
        {
            
            arr.push_back(elem);
            
        }
        if(i > 0)
        {
            sort(arr.begin(),arr.end());
            medianvec(arr);

        }
        
        
        
        
    }




    return 0;
}