# https://www.facebook.com/Skystar360/posts/377083483466548
# Subscribed by Ritika Singh
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    
    for(int i=0;i<s.length()/2;i++)
    {
        swap(s[i],s[s.size()-1-i]);
    }
    cout<<s;
    return 0;
}
