#include<bits/stdc++.h>


using namespace std;


int meanval(vector<int> arr)
{
    int v = arr.size();
    int sum = 0;
    for(int i=0; i<v; i++)
    {
        sum = sum + arr[i];
    }
    int avg=0;
    avg = sum/v;
    return avg;
}









int main()
{
    int elem;
    vector<int> arr;
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> elem;
        arr.push_back(elem);
    }
    
    int m = meanval(arr);
    cout << m << endl;
   






    return 0;
}