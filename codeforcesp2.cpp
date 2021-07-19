#include<bits/stdc++.h>


using namespace std;




int main()
{
    int count=0;
int64_t N,M,a,i=0;
cin >> N;
cin >> M;
cin >> a;
int64_t area,blockarea;
area = N*M;
int64_t total=0;
blockarea = a*a;
while(total < area)
{   total = blockarea * pow(2,i);
    i++;
}
cout << pow(2,i-1) << endl;



    return 0;
}