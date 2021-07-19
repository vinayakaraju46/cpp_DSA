/*
// Sample code to perform I/O:

cin >> name;                            // Reading input from STDIN
cout << "Hi, " << name << ".\n";        // Writing output to STDOUT

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here


#include<bits/stdc++.h>

using namespace std;

int main()
{
stack<char> stk;
  string str;  
  int T,k;
  cin >> T;
  for(int i=0;i<T;i++)
  {
      cin >> str;
      int count=0;
      for(k=0; k<str.size();k++)
      {   
          char temp1 = str[k];
          if(str.size() %2 != 0)
          {
              cout << "NO" << endl;
              break;
          }
          if(temp1 == '{' || temp1 == '[' || temp1 == '(')
          {
              stk.push(str[k]);
              
          }
          else
          {   
              char temp = stk.top();
              stk.pop();
              if(temp == '(' && str[k] == ')' || temp == '[' && str[k] == ']' || temp == '{' && str[k] == '}')
              {
                  count++;
              }
              else
              {
                  cout << "NO" << endl;
                  break;
              }
              
             
              
          }
          if(stk.size() == 0 && k==str.size()-1)
          {
              cout << "YES" << endl;
          }
          
        
        
      }
      
      
      while(stk.size() != 0)
      {
          stk.pop();
      }
      

    
  }
    

    
    
    
    return 0;
}