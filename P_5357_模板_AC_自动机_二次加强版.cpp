#include<bits/stdc++.h>
using namespace std;
int n,p[100005];
string s;
string read()
{
	string in;
	cin>>in;
	return " "+in;
}
struct trie{
	int to[33],end;
	int fail;
}e[2000005];
int ecnt=1;
void add(int d)
{
	int k=0;
	for(int i=1;i<s.size();i++)
		if(!e[k].to[s[i]-'a'+1]) e[k].to[s[i]-'a'+1]=++ecnt;
	e[k].end++;
	p[d]=k;
}
void get_fail()
{
	queue<int>q;
	e[0].fail=0;
	for(int i=1;i<=26;i++)
		if(e[0].to[i])
			e[e[0].to[i]].fail=0,q.push(e[0].to[i]);
	while(!q.empty())
	{
		int t=q.front();q.pop();
		for(int i=1;i<=26;i++)
			if(e[t].to[i])
				e[e[t].to[i]].fail=e[e[t].fail].to[i],
				q.push(e[t].to[i]);
			else
				e[t].to[i]=e[e[t].fail].to[i];
	}
}
int ans[100005];
void search()
{
	int len=s.size()-1,k=0;
	for(int i=1;i<=len;i++)
	{
		do
			k=e[k].to[s[i]-'a'+1];
		while(!k);
		ans[k]++;
	}
}
vector<int>r[100005];
void dfs(int t)
{
	for(int i=0;i<r[t].size();i++)
	{
		int v=e[t].to[i];
		dfs(v);
		ans[t]+=ans[v];
	}
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		s=read(),add(i);
	get_fail();
	s=read();
	search();
	for(int i=1;i<=ecnt;i++)
		r[i].emplace_back(i);
	dfs(1);
	for(int i=1;i<=n;i++)
		printf("%d\n",ans[p[i]]);
	return 0;
}
