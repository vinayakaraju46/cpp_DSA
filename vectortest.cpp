#include<bits/stdc++.h>


using namespace std;

void printarray(vector<int> arr1)
{
    for(int i=0; i<arr1.size(); i++)
    {
        cout << arr1[i] << " ";
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
printarray(arr1);



    return 0;
}