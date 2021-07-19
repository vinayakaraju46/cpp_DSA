#include<bits/stdc++.h>

using namespace std;

vector<int> findthem(int S, int R)
{
    int x = pow(10,S-1);
    int y = pow(10,S)-1;
    vector<int> arr;

    for(int i=x; i<=y; i++)
    {
        int sum = 0;
        int num = i;
        while(num > 0)
        {
            int d = num%10;
            sum = sum + d;
            num = num/10;
        }
        if(sum == R)
        {
            arr.push_back(i);
        }
    }
    return arr;
}

void printarray(vector<int> vec)
{
    for(int i=0; i<vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
}

int main()
{
int S, R;
cin >> S;
cin >> R;

vector<int> array = findthem(S,R);
printarray(array);



    return 0;
}