#include<bits/stdc++.h>
using namespace std;

vector< vector<int> > master;


void findCombinationsUtil(vector<int> arr, int index, 
                       int num, int reducedNum,int a, int b) 
{ 
    // Base condition 
    
    if (reducedNum < 0) 
        return; 
  
    // If combination is found, print it 
    if (reducedNum == 0) 
    {   vector<int> temp;
        // master.push_back(arr);
        for (int i = 0; i < index; i++) {
            //  int j = arr[i]; 
            temp.push_back(arr[i]);
        }
        // cout << master.size();
        master.push_back(temp);
        return; 
    } 
  
    // Find the previous number stored in arr[] 
    // It helps in maintaining increasing order 
    int prev = (index == 0)? a : arr[index-1]; 
  
    // note loop starts from previous number 
    // i.e. at array location index - 1 
    for (int k = prev; k <= b ; k++) 
    { 
        // next element of array is k 
        arr[index] = k;
  
        // call recursively with reduced number 
        findCombinationsUtil(arr, index + 1, num, 
                                 reducedNum - k,a,b); 
    } 
} 
  
/* Function to find out all combinations of 
   positive numbers that add upto given number. 
   It uses findCombinationsUtil() */
void findCombinations(int n, int p, int q) 
{ 
    // array to store the combinations 
    // It can contain max n elements 
    vector<int> arr(n,0);
    int a = p;
    int b = q ;
  
    //find all combinations 
    findCombinationsUtil(arr, 0, n, n,a,b); 
} 

// void findtheleastsize(vector<vector<int> arr)
// {
//     int max = INT_MAX;
//     for(int i=0; i<arr.size(); i++)
//     {
//         int size = size(arr[i]);

//     }
// }
  
// Driver code 

void printall(){
    for(int i = 0 ; i<master.size(); i++){
        for(int j = 0 ; j<master[i].size() ; j++){
            cout<<master[i][j]<<" ";
        }
        cout<<endl;
    }
}

void lexo(){
    int m = INT_MAX;
    int in;
    for(int i = 0 ; i<master.size() ; i++ ){
        int x = master[i].size();
        if(x<m){
            m=x;
            in = i;
        }
    }

    for(int j = 0 ; j < master[in].size() ; j++){
        cout<<master[in][j]<<" ";
    }
    cout<<endl;
}
int main() 
{ 
    int n; 
    int a;
    int b;
    cin >> n >> a >> b;
    findCombinations(n,a,b);
    if(master.size()==0)
    {
        cout<<"NO"<<endl;
        exit(0);
    }
    else
    {
        cout<<"YES"<<endl;
    }
    // findtheleastsize(master);
    // printall(); 
    lexo();

    return 0; 
} 