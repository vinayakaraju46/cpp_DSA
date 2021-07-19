#include<bits/stdc++.h>
using namespace std;

int factorial(int n)
{
    return ( n==1 || n == 0) ? 1: n*factorial(n-1);
}



int diverseDeputation(int m, int w) 
{   int result1=0,result2=0;
    if(w == 1 && m > 1)
    {   
       result2 = w*(factorial(m)/(factorial(m-2)*2)); 
       return result2;
    }
    if(m == 1 && m > 1)
    {
        result1 = m*(factorial(w)/(factorial(w-2)*2));
        return result1;
    }
    if(m > 1 && w > 1)
    {
        int sum = result1+result2;
        return sum;
    }
    
    else {
    return 0;
    }
    
}

int main()
{
   cout <<  diverseDeputation(2,2);
    
    return 0;
}