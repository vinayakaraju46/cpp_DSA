#include<bits/stdc++.h>


using namespace std;

void printarray(vector<int> arr1)
{
    for(int i=0; i<arr1.size(); i++)
    {
        cout << arr1[i] << " ";
    }
}

void swap(int *x,int *y)
{   
    int temp = *x;
    *x = *y;
    *y = temp;
    

}


int partition(vector<int>arr1,int low,int high)
{   
    int pivot = arr1[high];
    int i = low - 1;
    for(int j=low; j<high-1; j++)
    {
        if(arr1[j] <= pivot)
        {
            i++;
            swap(&arr1[i],&arr1[j]);
        }
    }
    swap(&arr1[i+1],&arr1[high]);
    // cout << i << " ";
    return i+1;

}

void quicksort(vector<int>arr1,int low,int high)
{
    if(low < high)
    {
        int pi = partition(arr1,low,high);
        quicksort(arr1,low,pi-1);
        quicksort(arr1,pi+1,high);
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
cout << "After swapping .." << endl;
quicksort(arr1,0,n-1);
printarray(arr1);







    return 0;
}