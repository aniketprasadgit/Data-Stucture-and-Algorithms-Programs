#include<iostream>
using namespace std;
int main()
{
   int a[3]={0,0,0};
   int current[10],i,top=-1;
 
   string s,ans="incorrect";
   cin>>s;
   for(i=0;i<s.length();i++)
   {
       if(s[i]=='[')
       {
         a[0]++;
          top++;
         current[top]=0;
       }
       else if(s[i]=='(')
       {
          a[1]++;
           top++;
          current[top]=1;
       }
       else if(s[i]=='{')
       {
           a[2]++;
            top++;
           current[top]=2;
       }
      else if(s[i]==']'&&current[top]==0)
      {
       a[0]--;
       top--;
       }
      else if(s[i]==')'&&current[top]==1)
       {
a[1]--;
top--;
}
      else if(s[i]=='}'&&current[top]==2)
      {
a[2]--;
top--;
}
      else break;
       if(i==s.length()-1)
       {
         if(a[0]==0&&a[1]==0&&a[2]==0)
         ans="correct";
         else ans="incorrect";
       }
     
   }
    cout<<ans;
}


