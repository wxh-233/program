#include<bits/stdc++.h>
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#define f(a,b,c) for(int a=b;a<=c;a++)
using namespace std;
namespace lsq {
    typedef int lsqxx;
    struct lq {
        struct lqbz {
            lsqxx v,w,nxt;
        } e[1000005];
        lsqxx h[1000005],cnt;
        inline void add(lsqxx u,lsqxx v,lsqxx w=1) {
            e[++cnt].v=v;
            e[cnt].w=w;
            e[cnt].nxt=h[u];
            h[u]=cnt;
        }
    void erase() {cnt=0;memset(h,0,sizeof(h));return;}
    #define F(z,u) for(int _=z.h[u],v=z.e[_].v,w=z.e[_].w;_;_=z.e[_].nxt,v=z.e[_].v,w=z.e[_].w)
    }q,p;
};
using namespace lsq;
int n,m;
int w[10005],sw[10005];
int x;
int vis[100005];
int dis[100005];
int scc,bs[100005],sz[100005];
int dfn[100005],low[100005],dfns;
int neww[10005],news[10005];
stack<int>s;
void tarjan(int t)
{
    low[t]=dfn[t]=++dfns;s.push(t);vis[t]=dis[t]=1;
    F(q,t)
    {
        if(!dfn[v]) tarjan(v),low[t]=min(low[t],low[v]);
        else if(dis[v]) low[t]=min(low[t],dfn[v]);
    }
    if(dfn[t]==low[t])
    {
        ++scc;int k;
        do{
            bs[k=s.top()]=scc;++sz[scc];
            dis[k]=0;s.pop();
        }while(k!=t);
    }
}
int rd[10005];
int dp[105][1005];
void dfs(int x)
{
    f(i,neww[x],m) dp[x][i]=news[x];
    F(p,x)
    {
        dfs(v);int k=m-neww[x];
        for(int i=k;i>=0;i--)
            f(j,0,i)
                dp[x][i+neww[x]]=max(dp[x][i+neww[x]],
                dp[v][j]+dp[x][i+neww[x]-j]);
    }
}
int main()
{
	cin>>n>>m;
    f(i,1,n) scanf("%d",&w[i]);
    f(i,1,n) scanf("%d",&sw[i]);
    f(i,1,n) scanf("%d",&x),q.add(x,i);
    f(i,1,n) if(!dfn[i]) tarjan(i);
    f(i,1,n) F(q,i) if(bs[i]!=bs[v]) p.add(bs[i],bs[v]),rd[bs[v]]++;memset(vis,0,sizeof(vis));
    f(i,1,n) neww[bs[i]]+=w[i],news[bs[i]]+=sw[i];
    f(i,1,scc) if(!rd[i]) p.add(0,i);
    dfs(0);
    cout<<dp[0][m];
	return 0;
}