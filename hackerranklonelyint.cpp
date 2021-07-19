#include<bits/stdc++.h>

using namespace std;

void printarray(vector<int> arr)
{
    for(int i=0; i<arr.size(); i++)
    {   
        cout << arr[i] << " ";
    }
}


int main()
{
int l,r;
vector<int> arr;
cin >> l;
cin >> r;
int count = 0;
for(int i=l;i<=r;i++)
{
    for(int j=l+count;j<=r;j++)
    {   
        // cout << i << " " << j << endl;
        arr.push_back(i^j);
    }
    count++;
}
// sort(arr.begin(),arr.end());
cout << *max_element(arr.begin(),arr.end());




    return 0;
}