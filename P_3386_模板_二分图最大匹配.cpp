#include<bits/stdc++.h>
using namespace std;
typedef int lsqxx;
struct lq{
    lsqxx v,nxt;
} e[500005];
lsqxx h[1005],cnt;
void add(int u,int v)
{
    e[++cnt].v=v;
    e[cnt].nxt=h[u];
    h[u]=cnt;
}
int re[1005],vis[1005],dis[1005];
int n,m,E,ans;
int x,y;
bool dfs(int t)
{
    for(int i=h[t];i;i=e[i].nxt)
	{
        int v=e[i].v;
        if(re[v]==t) continue;
        if(dis[v]) continue;
        dis[v]=1;
        if(!vis[v])
		{
            re[v]=t;
            vis[v]=1;
            return true;
        }
		else
		{
            if(dfs(re[v]))
			{
                vis[v]=1;
                re[v]=t;
                return true;
            }
        }
    }
    return false;
}
int main()
{
    cin>>n>>m>>E;
    for(int i=1;i<=E;i++)
        scanf("%d%d",&x,&y),add(x,y+n);
    for(int i=1;i<=n;i++)
	{
        memset(dis,0,sizeof(dis));
        if(dfs(i))
			ans++;
    }
    cout<<ans;
    return 0;
}