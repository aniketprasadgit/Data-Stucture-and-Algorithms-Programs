#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n,c;
	    cin>>n>>c;
	    int arrden[c], arrcur[n+1];
	   for(int i=0;i<=n;i++)
	        arrcur[i]=INT_MAX;
	    arrcur[0]=0;
	    for(int i=0;i<c;i++)
	        cin>>arrden[i], arrcur[arrden[i]]=1;
	   for(int i=0;i<=n;i++)
	   {
	       if( arrcur[i]!=INT_MAX){
	       for(int j=0;j<c;j++)
	       {
	           if(i+arrden[j]<=n)
	            arrcur[i+arrden[j]]=min(arrcur[i+arrden[j]],arrcur[i]+1);
	       }
	       }
	   }
	   if(arrcur[n]==INT_MAX)
	    cout<<-1<<endl;
	    else
	   cout<<arrcur[n]<<endl;

	}
	return 0;
}
