#include<bits/stdc++.h>
#include<string>

using namespace std;


string convert(string stri)
{
    if(stri.length() <= 10)
    {
        return stri;
    }
    else
    {
        ostringstream str1; 
        int  num = stri.substr(1,stri.length()-2).length();
        str1 << num;
        string s = str1.str();
        string strin = stri[0] + s + stri[stri.length()-1];
        return strin;
    }
    

}



int main()
{
    int n;
string instr;
cin >> n;
for(int i=0; i<n; i++)
{
    cin >> instr;
    int n = instr.length();

    cout << convert(instr) << endl;
}






    return 0;
}