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
        } e[4000005];
        lsqxx h[2000005],cnt;
        inline void add(lsqxx u,lsqxx v,lsqxx w=1) {
            e[++cnt].v=v;
            e[cnt].w=w;
            e[cnt].nxt=h[u];
            h[u]=cnt;
        }
    void erase() {cnt=0;memset(h,0,sizeof(h));return;}
    #define F(z,u) for(int j=z.h[u],v=z.e[j].v,w=z.e[j].w;j;j=z.e[j].nxt,v=z.e[j].v,w=z.e[j].w)
    }q;
};
using namespace lsq;
int n,m;
int x,a,y,b;
int vis[2000005];
int dis[2000005];
int scc,bs[2000005],sz[2000005];
int dfn[2000005],low[2000005],dfns;
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
int main()
{
	cin>>n>>m;
    f(i,1,m)
    {
        scanf("%d%d%d%d",&a,&x,&b,&y);
        if(x==0&&y==0) q.add(a+n,b),q.add(b+n,a);
        if(x==0&&y==1) q.add(a+n,b+n),q.add(b,a);
        if(x==1&&y==0) q.add(a,b),q.add(b+n,a+n);
        if(x==1&&y==1) q.add(a,b+n),q.add(b,a+n);
    }
    f(i,1,2*n) if(!dfn[i]) tarjan(i);
    f(i,1,n) if(bs[i]==bs[i+n]) {printf("IMPOSSIBLE\n");return 0;}
    printf("POSSIBLE\n");
    for(int i=1;i<=n;i++)
    {
        if(bs[i]>bs[i+n]) printf("1 ");
        else printf("0 ");
    }
	return 0;
}