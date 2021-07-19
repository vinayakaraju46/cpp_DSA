#include <bits/stdc++.h> 
using namespace std; 
vector<int> vec;  
// Function to return gcd of a and b 
int gcd(int a, int b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 
  
// Function to find gcd of array of 
// numbers 
int findGCD(vector<int> arr, int n) 
{ 
    int result = arr[0]; 
    for (int i = 1; i < n; i++) 
        result = gcd(arr[i], result); 
  
    return result; 
} 

void printArray(vector<int> arr, int n) 
{ 
    for (int i = 0; i < n; i++) 
        cout << arr[i] << " "; 
    cout << endl; 
} 

void printSubsequences(vector<int> arr, int index,  
                       vector<int> subarr,const int &k) 
{ 
    // Print the subsequence when reach 
    // the leaf of recursion tree 
    if (index == arr.size()) 
    { 
        int l = subarr.size(); 
  
        // Condition to avoid printing 
        // empty subsequence 
        if (l != 0 && l<=k) 
        {
            int x = findGCD(subarr,l);
            vector<int> :: iterator itr;
            itr = find(vec.begin(),vec.end(),x);
            if(itr == vec.end())
            {
                vec.push_back(x);
            }
            // // vec.push_back();
            // printArray(subarr,l);
        }
            // printArray(subarr, l); 
    } 
    else
    { 
        // Subsequence without including 
        // the element at current index 
        printSubsequences(arr, index + 1, subarr,k); 
  
        subarr.push_back(arr[index]); 
  
        // Subsequence including the element 
        // at current index 
        printSubsequences(arr, index + 1, subarr,k); 
    } 
    return; 
} 






  
// Driven code 
int main() 
{ 
    vector<int> arr;
    vector<int> b;
    // int arr[] = { 2, 4, 6, 8, 16 }; 
    int n,elem,k;
    cin >> n;
    cin >> k;
    for(int i=0; i<n; i++)
    {
        cin >> elem;
        arr.push_back(elem);
    }
    printSubsequences(arr,0,b,k);
    cout << vec.size();
    // int n = sizeof(arr) / sizeof(arr[0]); 
    // cout << findGCD(arr, n) << endl; 
    // for(int i=0; i<vec.size(); i++)
    // {
    //     cout << vec[i] << " ";
    // }
    return 0; 
}  