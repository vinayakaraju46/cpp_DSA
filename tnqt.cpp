#include<bits/stdc++.h>


using namespace std;

int reversDigits(int num) 
{ 
    int rev_num = 0; 
    while(num > 0) 
    { 
        rev_num = rev_num*10 + num%10; 
        num = num/10; 
    } 
    return rev_num; 
} 


int main()
{int temp1,temp2;
vector<int> sd;
int number,n1;
int result=0;
cin >> number;
n1 = number;
while (number > 0)
{
    int digit = number%10;
    number /= 10;
    sd.push_back(digit);
}
for(int j=0; j<sd.size();j++)
{
    result = result + sd[j];

}
temp1 = result;


temp2 = reversDigits(temp1);
// cout << temp1*temp2 << endl;
int pro = temp1*temp2;
if(n1 == pro)
{
    cout << n1 <<" is a magic number" << endl;
}
else
{
    cout << n1 << " is not a magic number"<< endl;
}






    return 0;
}