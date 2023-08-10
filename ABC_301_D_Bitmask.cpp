#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
string s;
int ans;
string read()
{
    string in;
    cin>>in;
    return " "+in;
}
void dfs(int i,int cnt)
{
    if(i==s.size())
    {
        cout<<cnt<<endl;
        exit(0);
    }
    if(s[i]=='?')
    {
        if(cnt+(1<<(s.size()-i-1))<=n)
            dfs(i+1,cnt|1<<(s.size()-i-1));
        dfs(i+1,cnt);
    }
    else
    {
        if(cnt+((s[i]-'0')<<(s.size()-i-1))>n)
        {
            // printf("-1\n");
            return;
        }
        dfs(i+1,cnt|(s[i]-'0')<<(s.size()-i-1));
    }
}
signed main()
{
	s=read();
    cin>>n;
    dfs(1,0);
    cout<<"-1\n";
	return 0;
}