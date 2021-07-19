#include<bits/stdc++.h>


using namespace std;

bool checkthem(int N)
{
    int i=2;
    int count =0;
    if(N <= 2)
    {
        return false;
    }
    while(i<=N)
    {
        int x = N-i;
        if(x%2 == 0 && i%2 == 0)
        {
            count++;
        }
        i = i*2;

    }
    if(count == 0)
    {
        return false;
    }
    else
    {
        return true;
    }
    
}


int main()
{

int N;
cin >> N;
bool x = checkthem(N);
if(x == true)
{
    cout << "YES" << endl;
}
if(x == false)
{
    cout << "NO" << endl;
}


    return 0;
}