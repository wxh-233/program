#include<bits/stdc++.h>
using namespace std;
namespace wxh666{
	#define getchar getchar_unlocked
	#define putchar putchar_unlocked
	#define sqrt(a) __builtin_sqrt(a)
	#define f(a,b,c) for(int a=b;a<=c;a++)
	inline int read()
	{
		char ch=getchar();int f=1,ans=0;
		for(;!isdigit(ch);ch=getchar()) ch=='-'?f=-1:f=1;
		for(;isdigit(ch);ch=getchar()) ans=(ans<<3)+(ans<<1)+(ch&15);
		return f*ans;
	}
	#define in read()
	#define cs(dt,n,m) \
    for(int i=1;i<=n;i++)\
    {\
        for(int j=1;j<=n;j++)\
            printf("%d ",dt[i][j]);\
        cout<<endl;\
    }
};using namespace wxh666;
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
    #define F(z,u) for(int j=z.h[u],v=z.e[j].v,w=z.e[j].w;j;j=z.e[j].nxt,v=z.e[j].v,w=z.e[j].w)
    }q,p;
};
using namespace lsq;
int n,m;
int x,y;
int tot;
int dfn[10005],low[10005];
int vis[10005],dis[10005];
int bz[10005],sz[10005];
stack<int>s;
int scc,dfns;
void tarjan(int t,int fa)
{
    low[t]=dfn[t]=++dfns;s.push(t);vis[t]=dis[t]=1;
    F(q,t)
    {
        if(v==fa) continue;
        if(!dfn[v]) tarjan(v,t),low[t]=min(low[t],low[v]);
        else if(dis[v]) low[t]=min(low[t],dfn[v]);
    }
    if(dfn[t]==low[t])
    {
        ++scc;int k;
        do{
            bz[k=s.top()]=scc;++sz[scc];
            low[k]=t,dis[k]=0;s.pop();
        }while(k!=t);
    }
}
int oula[10005],fo[10005],oucnt;
int d[10005];
void dfs(int t)
{
    oula[++oucnt]=t;
    fo[t]=oucnt;
    F(p,t)
    {
        if(oula[v]) continue;
        d[v]=d[t]+1;
        dfs(v);
        oula[++oucnt]=t;
    }
}
int f[20005][20];
void ten_to_two(int x)
{
    stack<int>r;
    while(x)
    {
        r.push(x&1);
        x>>=1;
    }
    while(!r.empty()) printf("%d",r.top()),r.pop();
    putchar('\n');
}
int ask(int l,int r)
{
    int k=log2(r-l+1);
    return min(f[l][k],f[r-(1<<k)+1][k]);
}
int main()
{
	cin>>n>>m;
    f(i,1,m) scanf("%d%d",&x,&y),q.add(x,y),q.add(y,x);
    f(i,1,n) if(!dfn[i]) tarjan(i,i);
    f(i,1,n) F(q,i)
        if(bz[i]!=bz[v])
            p.add(bz[i],bz[v]),p.add(bz[v],bz[i]);
    d[1]=1;
    dfs(1);
    // f(i,1,n) cerr<<i<<" "<<fo[i]<<endl;
    f(i,1,oucnt) f[i][0]=oula[i];
    f(j,1,16)
        f(i,1,scc-(1<<j)+1)
            f[i][j]=min(f[i][j-1],f[i+(1<<(j-1))][j-1]);
    cin>>tot;
    while(tot--)
    {
        scanf("%d%d",&x,&y);
        if(fo[bz[x]]>fo[bz[y]]) swap(x,y);
        ten_to_two(d[bz[x]]+d[bz[y]]-2*d[ask(fo[bz[x]],fo[bz[y]])]+1);
    }
	return 0;
}