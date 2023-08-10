#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
int n;
ull has;
map<ull,bool>q;
string s;
string read()
{
    string in;
    cin>>in;
    return " "+in;
}
int main()
{
	cin>>n;
    for(int i=1;i<=n;i++)
    {
        s=read();
        has=0;
        int x=1,y=s.size()-1;
        while(s[x]==s[y]&&x<y) x++,y--;
        if(s[x]<s[y])
        {
            for(int j=1;j<s.size();j++)
                has=has*131+s[j];
            q[has]=true;
        }
        else
        {
            for(int j=s.size()-1;j>=1;j--)
                has=has*131+s[j];
            q[has]=true;
        }
    }
    cout<<q.size();
	return 0;
}