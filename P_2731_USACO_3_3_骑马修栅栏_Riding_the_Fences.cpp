#include<bits/stdc++.h>
#define int long long
using namespace std;
int dt[505][505],vis[505][505];
int m,n,minx=1e15;
int x,y;
int ans[1025],d[505];
void print()
{
	for(int i=1;i<=m+1;i++)
		printf("%lld\n",ans[i]);
}
int cnt,fcnt;
void dfs(int t)
{
	ans[++cnt]=t;
	if(cnt+(m+2-fcnt)>m)
	{
		print();
		exit(0);
	}
	for(int i=minx;i<=n;i++)
	{
		if(dt[t][i]&&(vis[t][i]<dt[t][i]))
		{
			vis[t][i]++;
			vis[i][t]++;
			dfs(i);
		}
	}
	ans[--fcnt]=t;
	cnt--;
}
signed main()
{
	cin>>m;fcnt=m+2;
	for(int i=1;i<=m;i++)
	{
		scanf("%lld%lld",&x,&y);
		n=max(n,max(x,y));minx=min(minx,(min(x,y)));
		dt[x][y]++;dt[y][x]++;
		d[x]++,d[y]++;
	}
	for(int i=minx;i<=n;i++)
		if(d[i]&1)
			dfs(i);
	dfs(minx);
	return 0;
}