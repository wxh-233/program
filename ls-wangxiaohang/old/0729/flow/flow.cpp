#include<bits/stdc++.h>
using namespace std;
#define N 50005
namespace wxh666{
    #define getchar getchar_unlocked
    #define putchar putchar_unlocked
    #define f(a,b,c) for(int a=b;a<=c;a++)
    inline int read()
    {
        char ch=getchar();int f=1,ans=0;
        for(;!isdigit(ch);ch=getchar()) ch=='-'?f=-1:f=1;
        for(;isdigit(ch);ch=getchar()) ans=(ans<<3)+(ans<<1)+(ch&15);
        return f*ans;
    }
    #define in read()
};using namespace wxh666;
namespace lsq {
    typedef int lsqxx;
    struct lq {
        struct lqbz {
            lsqxx v,nxt;
        } e[2*N];
        lsqxx h[N],cnt;
        inline void add(lsqxx u,lsqxx v) {
            e[++cnt].v=v;
            e[cnt].nxt=h[u];
            h[u]=cnt;
        }
    void erase() {cnt=0;memset(h,0,sizeof(h));return;}
    #define F(z,u) for(int j=z.h[u],v=z.e[j].v;j;j=z.e[j].nxt,v=z.e[j].v)
    }q;
};
using namespace lsq;
struct x_trees{
    struct{
        int l,r,sum,lan;
    }t[2000005];
    void build(int k,int l,int r)
    {
        t[k].l=l;t[k].r=r;
        if(l==r) return;
        int mid=l+r>>1;
        build(k<<1,l,mid);
        build((k<<1)+1,mid+1,r);
    }
};
struct max_x_trees:public x_trees{
    void down(int k)
    {
        if(!t[k].lan) return;
        t[k<<1].sum+=t[k].lan;t[k<<1].lan+=t[k].lan;
        t[k<<1|1].sum+=t[k].lan;t[k<<1|1].lan+=t[k].lan;
        t[k].lan=0;
    }
    void add(int k,int x,int y,int z)
    {
        if(t[k].l>y||t[k].r<x) return;
        if(t[k].l>=x&&t[k].r<=y)
        {
            t[k].sum+=z;
            t[k].lan+=z;
            return;
        }
        down(k);
        add(k<<1,x,y,z);
        add((k<<1)+1,x,y,z);
        t[k].sum=max(t[k<<1].sum,t[(k<<1)+1].sum);
    }
    int ask(int k,int x,int y)
    {
        if(t[k].l>y||t[k].r<x) return 0;
        if(t[k].l>=x&&t[k].r<=y) return t[k].sum;
        down(k);
        return max(ask(k<<1,x,y),ask((k<<1)+1,x,y));
    }
}trees;
struct d{
    int d,fa,siz,big;
    int dfn,top;
}e[N];
int dfns=0;
int n,k;
int x,y;
int vis[N];
void dfs1(int t)
{
    e[t].siz=1;
    int maxn=0;
    F(q,t)
    {
        if(vis[v]) continue;
        vis[v]=1;
        e[v].fa=t;
        e[v].d=e[t].d+1;
        dfs1(v);
        if(maxn<e[v].siz)
            e[t].big=v,maxn=e[v].siz;
        e[t].siz+=e[v].siz;
    }
}
void dfs2(int t,int top)
{
    e[t].top=top;
    e[t].dfn=++dfns;
    if(e[t].big) vis[e[t].big]=1,dfs2(e[t].big,top);
    F(q,t)
    {
        if(vis[v]) continue;
        if(v==e[t].big) continue;
        vis[v]=1;
        dfs2(v,v);
    }
}
void change_line(int x,int y)
{
    if(e[x].top==e[y].top)
    {
        if(e[x].dfn>e[y].dfn) swap(x,y);
        trees.add(1,e[x].dfn,e[y].dfn,1);
        return;
    }
    if(e[e[x].top].d>e[e[y].top].d) swap(x,y);
    trees.add(1,e[e[y].top].dfn,e[y].dfn,1);
    change_line(x,e[e[y].top].fa);
}
int main()
{
    // freopen("flow.in","r",stdin);
    // freopen("flow.out","w",stdout);
    cin>>n>>k;
    trees.build(1,1,n+1);
    f(i,1,n-1) scanf("%d%d",&x,&y),q.add(x,y),q.add(y,x);
    e[1].d=1;vis[1]=1;
    dfs1(1);
    memset(vis,0,sizeof(vis));vis[1]=1;
    dfs2(1,1);
    f(i,1,k)
    {
        x=in;y=in;
        change_line(x,y);
    }
    cout<<trees.t[1].sum;
    return 0;
}