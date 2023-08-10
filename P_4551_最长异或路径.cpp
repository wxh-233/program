#include<bits/stdc++.h>
using namespace std;
namespace lsq
{
	struct lq{
		struct lqbz {
			int v,w,nxt;
		}e[2000005];
		int h[1000005],cnt;
		inline void add(int u,int v,int w=1) {
			e[++cnt].v=v;
			e[cnt].w=w;
			e[cnt].nxt=h[u];
			h[u]=cnt;
		}
	}g;
};
bool vis[100005];
using namespace lsq;
struct trie{
	int to[2];
}e[3000005];
int ecnt=1;
int n;
int x,y,z;
int sum[1000005],cntsum;
void add(int cnt)
{
	int i=1;
	for(int k=31;k>=0;i=e[i].to[(cnt>>k)&1],k--)
	{
		if(!e[i].to[(cnt>>k)&1]) e[i].to[(cnt>>k)&1]=++ecnt;
	}
}
void dfs(int t,int cnt)
{
	sum[++cntsum]=cnt;
	add(cnt);
	for(int j=g.h[t],v=g.e[j].v,w=g.e[j].w;j;j=g.e[j].nxt,v=g.e[j].v,w=g.e[j].w)
	{
		if(vis[v]) continue;
		vis[v]=true;
		dfs(v,cnt^w);
	}
}
int ans;
void dfs2(int t,int now,int k,int cnt)
{
	if(k<0)
	{
		ans=max(ans,cnt);
		return;
	}
	if(e[t].to[((now>>k)&1)^1])
		dfs2(e[t].to[((now>>k)&1)^1],now,k-1,cnt|(1<<k));
	else
		dfs2(e[t].to[(now>>k)&1],now,k-1,cnt);
	return;
}
signed main()
{
	cin>>n;
	for(int i=2;i<=n;i++)
	{
		int p=scanf("%d%d%d",&x,&y,&z);
		g.add(x,y,z);
		g.add(y,x,z);
	}
	dfs(1,0);
	for(int i=1;i<=cntsum;i++)
		dfs2(1,sum[i],31,0);
	cout<<ans<<endl;
	return 0;
}