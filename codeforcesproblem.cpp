#include<bits/stdc++.h>

using namespace std;


bool checkdiv(int W)
{
    while(W > 0)
    {
        int x = W/2;
        if(x%2 != 0)
        {
            return false;
        }
        W = W/2;
    }
    return true;
}

int main()
{
    int W;
    cin >> W;

    cout << checkdiv(W) << endl;



    return 0;
}