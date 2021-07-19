#include<bits/stdc++.h>


using namespace std;

void swap(int *x, int *y)
{
    int t = *x;
    *x = *y;
    *y = t;
}


int partition(int arr[],int low, int high)
{
    int pivot = arr[high];
    int i = low-1;
    for(int j=low;j<=high-1;j++)
    {   
        if(arr[j] <= pivot)
        {
            i++;
            swap(&arr[i],&arr[j]);
        }
        

    }
    swap(&arr[i+1],&arr[high]);
    return i+1;
}

void quicksort(int arr[],int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr,low,high);
        quicksort(arr,low,pi-1);
        quicksort(arr,pi+1,high);
    }
}



int main()
{
int arr[5] = {10,9,8,7,6};
quicksort(arr,0,4);

for(int i=0; i<5; i++)
{
    cout << arr[i] << " " ;
}




    return 0;
}