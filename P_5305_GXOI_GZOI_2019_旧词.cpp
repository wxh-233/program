#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int pows[50005];
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
            printf("%lld ",dt[i][j]);\
        cout<<endl;\
    }
};using namespace wxh666;
namespace lsq {
    typedef int lsqxx;
    struct lq {
        struct lqbz {
            lsqxx v,w,nxt;
        } e[2000005];
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
struct sp{
    int d,fa,big,siz;
    int dfn,top,fdfn;
}t[500005];int dfnt;
struct x_trees{
    struct{
        int l,r,sum,lan,d,qz;
    }e[5000005];
    void build(int k,int l,int r)
    {
        e[k].l=l;e[k].r=r;
        if(l==r)
        {
            e[k].qz=pows[t[t[l].fdfn].d];
            return;
        }
        int mid=l+r>>1;
        e[k<<1].d=e[k<<1|1].d=e[k].d+1;
        build(k<<1,l,mid);
        build((k<<1)+1,mid+1,r);
        e[k].qz=e[k<<1].qz+e[k<<1|1].qz;
    }
};
struct sum_x_trees:public x_trees{
    void down(int k)
    {
        if(!e[k].lan) return;
        e[k<<1].lan+=e[k].lan;
        e[k<<1].lan%=mod;
        e[k<<1].sum+=e[k].lan*(e[k<<1].qz%mod);
        e[k<<1].sum%=mod;
        e[(k<<1)+1].lan+=e[k].lan;
        e[k<<1|1].lan%=mod;
        e[(k<<1)+1].sum+=e[k].lan*(e[k<<1|1].qz%mod);
        e[k<<1|1].sum%=mod;
        e[k].lan=0;
    }
    void add(int k,int x,int y,int z)
    {
        if(e[k].l>y||e[k].r<x) return;
        if(e[k].l>=x&&e[k].r<=y)
        {
            e[k].sum+=e[k].qz*(z%mod)%mod;
            e[k].sum%=mod;
            e[k].lan+=z;
            e[k].lan%=mod;
            return;
        }
        down(k);
        add(k<<1,x,y,z);
        add((k<<1)+1,x,y,z);
        e[k].sum=e[k<<1].sum+e[(k<<1)+1].sum;
        e[k].sum%=mod;
    }
    int ask(int k,int x,int y)
    {
        if(e[k].l>y||e[k].r<x) return 0;
        if(e[k].l>=x&&e[k].r<=y) return e[k].sum;
        down(k);
        return (ask(k<<1,x,y)+ask((k<<1)+1,x,y))%mod;
    }
}trees;
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
    t[dfnt].fdfn=now;
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
int n,m,k;
int l,r,z;
int ans[500005];
struct que{
    int r,xh,x;
}e[500005];
int fpow(int x,int k,int p=mod)
{
    int ans=1;
    while(k)
    {
        if(k&1) ans=ans*x%p;
        x=x*x%p;k>>=1;
    }
    return ans;
}
signed main()
{
	cin>>n>>m>>k;
    f(i,2,n) z=read(),q.add(z,i);
    f(i,1,n) pows[i]=(fpow(i,k)-fpow(i-1,k)+mod)%mod;
    t[1].d=1;t[1].fa=1;
    dfs1(1);dfs2(1,1);
    trees.e[1].d=1;
    trees.build(1,1,n);
    f(i,1,m)
    {
        r=read();z=read();
        e[i].xh=i;
        e[i].r=r;
        e[i].x=z;
    }
    sort(1+e,1+e+m,[&](auto x,auto y){
        return x.r<y.r;
    });
    f(i,1,m)
    {
        if(e[i].r>e[i-1].r)
            f(j,e[i-1].r+1,e[i].r)
                change_line(j,1);
        ans[e[i].xh]+=search_line(e[i].x);
    }
    f(i,1,m) printf("%lld\n",(ans[i]+mod)%mod);
	return 0;
}