#include<bits/stdc++.h>


using namespace std;

int returnval(vector<int> arr,int k)
{
    int n = arr.size();
    int count = 0;
    if(arr[0] == 0)
    {
        return 0;
    }
 
    // int count = 0;
    for(int j=0; j<k-1; j++)
    {
        if(arr[j] >= arr[j+1] && arr[j] > 0 && arr[j+1] > 0)
        {
            count++;
        }
    }
    for(int l=k; l<n-1; l++)
    {
        if(arr[k-1] == arr[l])
        {
            count++;
        }
    }

return count+1;



}






int main()
{
int n,k,elem;
vector<int> arr;
cin >> n;
cin >> k;

for(int i=0; i<n; i++)
{
    cin >> elem;
    arr.push_back(elem);
}


cout << endl;
cout << returnval(arr,k) << endl; 




    return 0;
}