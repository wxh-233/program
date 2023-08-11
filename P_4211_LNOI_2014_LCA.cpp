#include<bits/stdc++.h>
using namespace std;
const int mod=201314;
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
		return f*ans+1;
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
struct sum_x_trees:public x_trees{
    void down(int k)
    {
        t[k<<1].lan+=t[k].lan;
        t[k<<1].lan%=mod;
        t[k<<1].sum+=(t[k<<1].r-t[k<<1].l+1)*t[k].lan;
        t[k<<1].sum%=mod;
        t[(k<<1)+1].lan+=t[k].lan;
        t[k<<1|1].lan%=mod;
        t[(k<<1)+1].sum+=(t[(k<<1)+1].r-t[(k<<1)+1].l+1)*t[k].lan;
        t[k<<1|1].sum%=mod;
        t[k].lan=0;
    }
    void add(int k,int x,int y,int z)
    {
        if(t[k].l>y||t[k].r<x) return;
        if(t[k].l>=x&&t[k].r<=y)
        {
            t[k].sum+=(t[k].r-t[k].l+1)*(z%mod);
            t[k].sum%=mod;
            t[k].lan+=z;
            t[k].lan%=mod;
            return;
        }
        down(k);
        add(k<<1,x,y,z);
        add((k<<1)+1,x,y,z);
        t[k].sum=t[k<<1].sum+t[(k<<1)+1].sum;
        t[k].sum%=mod;
    }
    int ask(int k,int x,int y)
    {
        if(t[k].l>y||t[k].r<x) return 0;
        if(t[k].l>=x&&t[k].r<=y) return t[k].sum;
        down(k);
        return (ask(k<<1,x,y)+ask((k<<1)+1,x,y))%mod;
    }
}trees;
struct sp{
    int d,fa,big,siz;
    int dfn,top;
}t[50005];int dfnt;
void dfs1(int now)
{
    t[now].siz=1;
    int bsiz=0;
    F(q,now)
    {
        t[v].fa=now;
        t[v].d=t[now].d+1;
        dfs1(v);
        if(t[v].siz>bsiz) bsiz=t[v].siz,t[now].big=v;
        t[now].siz+=t[v].siz;
    }
}
void dfs2(int now,int tp)
{
    t[now].dfn=++dfnt;
    t[now].top=tp;
    if(t[now].big) dfs2(t[now].big,tp);
    F(q,now)
    {
        if(v==t[now].big) continue;
        dfs2(v,v);
    }
}
void change_line(int x,int y)
{
    trees.add(1,t[t[x].top].dfn,t[x].dfn,y);
    if(t[x].top==1) return;
    change_line(t[t[x].top].fa,y);
}
int search_line(int x)
{
    if(t[x].top==1) return trees.ask(1,t[t[x].top].dfn,t[x].dfn);
    return (trees.ask(1,t[t[x].top].dfn,t[x].dfn)+search_line(t[t[x].top].fa))%mod;
}
int n,m;
int l,r,z;
int ans[50005];
struct que{
    int r,xh,x,f;
}e[100005];
int main()
{
	cin>>n>>m;
    f(i,2,n) z=read(),q.add(z,i);
    t[1].d=1;t[1].fa=1;
    dfs1(1);dfs2(1,1);
    trees.build(1,1,n);
    f(i,1,m)
    {
        l=read();r=read();z=read();
        e[i*2-1].xh=i;
        e[i*2-1].r=l-1;
        e[i*2-1].f=-1;
        e[i*2-1].x=z;
        e[i*2].xh=i;
        e[i*2].r=r;
        e[i*2].f=1;
        e[i*2].x=z;
    }
    sort(1+e,1+e+2*m,[&](auto x,auto y){
        return x.r<y.r;
    });
    f(i,1,m*2)
    {
        if(e[i].r>e[i-1].r)
            f(j,e[i-1].r+1,e[i].r)
                change_line(j,1);
        ans[e[i].xh]+=e[i].f*search_line(e[i].x);
    }
    f(i,1,m) printf("%d\n",(ans[i]+mod)%mod);
	return 0;
}