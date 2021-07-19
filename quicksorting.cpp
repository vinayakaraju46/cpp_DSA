#include<bits/stdc++.h>

using namespace std;


void display(const int &n, int *arr)
{
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
}











int main()
{
int n,elem;
cout << "Enter the number of elements in an Array.." << endl;
cin >> n;
int *arr;
arr = new int[n];


for(int i=0; i<n; i++)
{
    cin >> elem;
    arr[i] = elem;
}
display(n,arr);



    return 0;
}