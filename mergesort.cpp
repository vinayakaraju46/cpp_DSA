#include<bits/stdc++.h>


using namespace std;


void merge(int arr[],int low,int middle,int high)
{
    int i,j,k;
    int n1 = middle - low + 1;
    int n2 = high - middle;
    int L[n1],R[n2];

    for(i=0; i<n1; i++)
    {
        L[i] = arr[low+i];
    }
    for(j=0;j<n2;j++)
    {
        R[j] = arr[middle+1+j];
    }
    j=0;
    i=0;
    k=low;
    while(i<n1 && j<n2)
    {
        if(L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
        
    }
    while(i<n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }

}





void mergesort(int arr[], int low, int high)
{
    if(low<high)
    {
        int middle = low+(high-low)/2;
        mergesort(arr,low,middle);
        mergesort(arr,middle+1,high);
        merge(arr,low,middle,high);
    }
}


void printarray(int arr[],int size)
{
    for(int i=0; i<size; i++)
    {
        cout << arr[i] << " ";
    }
}



int main()
{
int arr[] = {5,2,4,1,3};
int arr_size = sizeof(arr)/sizeof(arr[0]);
cout << "Before Sorting.." << endl;
printarray(arr,arr_size);
mergesort(arr,0,arr_size-1);
cout << "After Sorting.." << endl;
printarray(arr,arr_size);


    return 0;
}