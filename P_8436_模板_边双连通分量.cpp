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
        } e[8000005];
        lsqxx h[2000005],cnt=1;
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
int x,y;
stack<int>s;
vector<int>p[2000005];
int vis[2000005];
int dis[2000005];
int scc,bs[2000005],sz[2000005];
int dfn[2000005],low[2000005],dfns;
void tarjan(int x,int f)
{
    dfn[x]=low[x]=++dfns,s.push(x);vis[x]=dis[x]=1;
    F(q,x)
    {
        if(!dfn[v]) tarjan(v,j),low[x]=min(low[x],low[v]);
        else if(f!=(j^1)&&dis[v]) low[x]=min(low[x],dfn[v]);
    }
    if(dfn[x]==low[x])
    {
        ++scc;int j;
        do{
            bs[j=s.top()]=scc;sz[scc]++;dis[j]=0;
            // cerr<<j<<" : "<<dfn[j]<<" "<<low[j]<<endl;
            p[scc].push_back(j=s.top());s.pop();
        }while(j!=x);
        // cerr<<x<<" "<<sz[scc]<<endl;
    }
}
int main()
{
	cin>>n>>m;
    f(i,1,m) scanf("%d%d",&x,&y),q.add(x,y),q.add(y,x);
    f(i,1,n) if(!dfn[i]) tarjan(i,i);
    cout<<scc<<endl;
    f(i,1,scc)
    {
        printf("%d ",p[i].size());
        for(auto j:p[i])
            printf("%d ",j);
        printf("\n");
    }
	return 0;
}