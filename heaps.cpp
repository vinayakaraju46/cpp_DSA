#include<bits/stdc++.h>

using namespace std;

class Heap
{
    public:
        vector<int> arr;
        int currpos;
        Heap()
        {
            currpos = -1;
        }

        void insert(const int &val)
        {
            currpos+=1;
            arr[currpos] = val;
            fixup(currpos);  
            
        }

        void fixup(const int &index)
        {
            int parentindex = (int)(index-1)/2;
            while(parentindex >= 0 && arr[parentindex] < arr[index])
            {
                int temp = arr[index];
                arr[index] = arr[parentindex];
                arr[parentindex] = temp;
                parentindex = (int)(index-1)/2;
            }
        }

        void heapsort()
        {
            for(int k=0; k<currpos+1;k++)
            {
                int temp = arr[0];
                cout << temp << " " << endl;
                arr[0] = arr[currpos-k];
                arr[currpos-k] = temp;
                fixdown(0,currpos-k-1);

            }
        }

        void fixdown(int index, int upto)
        {
            while(index <= upto)
            {
                int leftchild = 2*index+1;
                int rightchild = 2*index+2;
                if(leftchild < upto)
                {
                    int childToSwap = NULL;
                    if(rightchild > upto)
                    {
                        childToSwap = leftchild;
                    }
                    else
                    {
                        if(arr[leftchild] > arr[rightchild])
                        {
                            childToSwap = leftchild;
                        }
                        else
                        {
                            childToSwap = rightchild;
                        }
                    }

                    if(arr[index] < arr[childToSwap])
                    {
                        int temp = arr[index];
                        arr[index] = arr[childToSwap];
                        arr[childToSwap] = temp;
                    }
                    else
                    {
                        break;
                    }
                    index = childToSwap;
                    
                    
                }
                else
                {
                    break;
                }
                
            }
        }





        void display()
        {
            for(int j=0; j<arr.size();j++)
            {
                cout << arr[j] << " ";
            }
        }


};




int main()
{
Heap hp;
int n,elem;
cin >> n;
for(int i=0;i<n;i++)
{
    cin >> elem;
    hp.insert(elem);
}

hp.display();

    return 0;
}