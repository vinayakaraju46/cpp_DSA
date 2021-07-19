#include<bits/stdc++.h>


using namespace std;


void printarray(vector<int> arr)
{
    for(int i=0; i<arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
}

int countFreq(vector<int>arr,int n)
{
    map<int, int> mp;
    for(int i=0;i<n;i++)
    {
     mp[arr[i]]++;
    }

for (int i = 0; i < n; i++) 
{ 
      if (mp[arr[i]] == 1) 
      { 
        //   cout << arr[i] << endl; 
        mp[arr[i]] = -1; 
        return arr[i];
          
      } 
} 

}


int main()
{
vector<int> arr;

int n,elem;
cin >> n;
for(int j=0; j<n; j++)
{
    cin >> elem;
    arr.push_back(elem);
}

 int result = countFreq(arr,n);

cout << result << endl;

    return 0;
}