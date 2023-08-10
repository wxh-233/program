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
int k,n,m;
char x,y;
int a,b;
int vis[2000005];
int dis[2000005];
int scc,bs[2000005],sz[2000005];
int dfn[2000005],low[2000005],dfns;
stack<int>s;
string xx,yy;
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
    cin>>k;
    while(k--)
    {
        q.erase();
        memset(bs,0,sizeof(bs));
        memset(sz,0,sizeof(sz));
        memset(vis,0,sizeof(vis));
        memset(dis,0,sizeof(dis));
        memset(dfn,0,sizeof(dfn));
        memset(low,0,sizeof(low));
        dfns=scc=0;
        while(!s.empty()) s.pop();
        scanf("%d%d",&n,&m);
        f(_,1,m)
        {
            cin>>xx>>yy;
            x=xx[0];y=yy[0];
            a=b=0;
            f(i,1,xx.size()-1) a=a*10+(xx[i]-'0');
            f(i,1,yy.size()-1) b=b*10+(yy[i]-'0');
            if(x=='m'&&y=='m') q.add(a+n,b),q.add(b+n,a);
            if(x=='m'&&y=='h') q.add(a+n,b+n),q.add(b,a);
            if(x=='h'&&y=='h') q.add(a,b+n),q.add(b,a+n);
            if(x=='h'&&y=='m') q.add(a,b),q.add(b+n,a+n);
        }
        f(i,1,n*2) if(!dfn[i]) tarjan(i);
        int flag=0;
        f(i,1,n) if(bs[i]==bs[i+n]) {flag=1;break;}
        if(flag) printf("BAD\n");
        else printf("GOOD\n");
    }
	return 0;
}