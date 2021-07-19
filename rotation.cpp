#include<bits/stdc++.h>

using namespace std;


int main()
{   vector<int> arr;
    int n,d,elem;
    cin >> n;
    cin >> d;
    for(int i=0;i<n;i++)
    {   cin >> elem;
        arr.push_back(elem);
    }

    for(int j=0; j < d; j++)
    {   
        int temp = arr[0],k=n-1;
        for(int k=0;k<n-1;k++)
        {
            arr[k] = arr[k+1];
        }
        arr[k] = temp;
    }

    for(int l=0; l<n;l++)
    {
        cout << arr[l] << " " ;
    }



    return 0;
}