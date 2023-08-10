#include<bits/stdc++.h>
using namespace std;
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
const int inf=0x3f3f3f3f;
int n,m,d;
int w[500005];
int vis[500005];
int f[500005][21],g[500005][21];
int x,y;
void dfs(int t,int fa)
{
    if(vis[t]) f[t][0]=g[t][0]=w[t];
    f(i,1,d) g[t][i]=w[t];
    g[t][d+1]=inf;
    F(q,t)
    {
        if(v==fa) continue;
        dfs(v,t);
        for(int i=d;i>=0;i--) g[t][i]=min(g[t][i]+f[v][i],g[v][i+1]+f[t][i+1]);
        for(int i=d;i>=0;i--) g[t][i]=min(g[t][i],g[t][i+1]);
        f[t][0]=g[t][0];
        f(i,1,d+1) f[t][i]+=f[v][i-1];
        f(i,1,d+1) f[t][i]=min(f[t][i],f[t][i-1]);
    }
}
int main()
{
	cin>>n>>d;
    f(i,1,n) w[i]=in;
    cin>>m;
    f(i,1,m) vis[in]=true;
    f(i,1,n-1) x=in,y=in,q.add(x,y),q.add(y,x);
    dfs(1,0);
    cout<<f[1][0]<<endl;
	return 0;
}