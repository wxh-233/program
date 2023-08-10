#include<bits/stdc++.h>
using namespace std;
map<string,int>q;
string s[105];
string g[105];
int ans;
int n,m;
int git,gits;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>s[i];
	for(int i=1;i<=m;i++)
		cin>>g[i];
	cin>>gits;
	for(int i=1;i<=m;i++)
		cin>>git,q[g[i]]=git;
	for(int i=1;i<=n;i++)
	{
		if(q[s[i]])
			ans+=q[s[i]];
		else
			ans+=gits;
	}
	cout<<ans<<endl;
	return 0;
}