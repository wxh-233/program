#include<bits/stdc++.h>
#define int long long
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
    }q;
};
using namespace lsq;
struct line{
    int u,v;
}t[1000005];
int n,Q;
int op,u,k;
int dfn[1000005],siz[1000005],dfns;
void dfs(int now)
{
    dfn[now]=++dfns;
    siz[now]=1;
    F(q,now)
    {
        if(dfn[v]) continue;
        dfs(v);
        siz[now]+=siz[v];
    }
}
int cf[1000005],ans[1000005];
signed main()
{
    // freopen("tree.in","r",stdin);
    // freopen("tree.out","w",stdout);
    cin>>n;
    cin>>Q;
    f(i,1,n-1) scanf("%lld%lld",&t[i].u,&t[i].v),q.add(t[i].u,t[i].v),q.add(t[i].v,t[i].u);
    dfs(1);
    f(i,1,Q)
    {
        scanf("%lld%lld%lld",&op,&u,&k);
        int x=t[u].u,y=t[u].v;
        if(op==1)
        {
            if(dfn[x]>dfn[y])
            {
                cf[dfn[x]]+=k;
                cf[dfn[x]+siz[x]]-=k;
            }
            else
            {
                cf[dfn[y]]-=k;
                cf[dfn[y]+siz[y]]+=k;
                cf[1]+=k;
            }
        }
        else
        {
            if(dfn[y]>dfn[x])
            {
                cf[dfn[y]]+=k;
                cf[dfn[y]+siz[y]]-=k;
            }
            else
            {
                cf[dfn[x]]-=k;
                cf[dfn[x]+siz[x]]+=k;
                cf[1]+=k;
            }
        }
    }
    f(i,1,n) ans[i]=ans[i-1]+cf[i];
    f(i,1,n) printf("%lld\n",ans[dfn[i]]);
    return 0;
}