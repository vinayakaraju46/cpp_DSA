#include<bits/stdc++.h>

using namespace std;


void printarray(vector<int> arr1)
{
    for(int j=0; j<arr1.size(); j++)
    {
        cout << arr1[j] << " ";
    }
}


int main()
{
vector<int> arr1;
int n,elem;
cout << "Enter the number of elements in a list.." << endl;
cin >> n;
for(int i=0; i<n; i++)
{
    cin >> elem;
    arr1.push_back(elem);
}
cout << "Before sorting.." << endl;
printarray(arr1);
cout << endl;

int key,k,l,count=0;
for(k=1; k < n; k++)
{
    key = arr1[k];
    l = k-1;
    while(l>=0 && arr1[l]>key)
    {   count++;
        arr1[l+1] = arr1[l];
        l = l-1;
    }
    arr1[l+1] = key;
}

printarray(arr1);
cout << endl;
cout << count << endl;

    return 0;
}