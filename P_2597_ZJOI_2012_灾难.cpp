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
    }q,p;
};
using namespace lsq;
int n;
int rd[100005];
int x;
int d[100005];
int f[100005],bz[100005][18];
int lca(int x,int y)
{
    // cerr<<x<<" and "<<y<<endl;
    if(x==y) return x;
    if(d[x]<d[y]) swap(x,y);
    for(int i=16;i>=0;i--) if(d[bz[x][i]]>=d[y]) x=bz[x][i];
    if(x==y) return x;
    for(int i=16;i>=0;i--) if(bz[x][i]!=bz[y][i]) x=bz[x][i],y=bz[y][i];
    // cerr<<x<<" to "<<y<<" is "<<bz[x][0]<<endl;
    return bz[x][0];
}
void tp()
{
    queue<int>t;
    f(i,1,n) f[i]=-1;
    f(i,1,n) if(rd[i]==0) t.push(i),f[i]=0,d[i]=1;
    while(!t.empty())
    {
        int now=t.front();t.pop();
        p.add(now,f[now]),p.add(f[now],now);
        d[now]=d[f[now]]+1;bz[now][0]=f[now];
        // cerr<<now<<" fais "<<bz[now][0]<<endl;
        f(i,1,16) bz[now][i]=bz[bz[now][i-1]][i-1];
        F(q,now)
        {
            rd[v]--;
            if(!rd[v]) t.push(v);
            if(f[v]==-1) f[v]=now;
            else f[v]=lca(f[v],now);
        }
    }
}
int vis[100005],ans[100005];
void dfs(int t)
{
    ans[t]=1;
    F(p,t)
    {
        if(vis[v]) continue;
        vis[v]=1;dfs(v);
        ans[t]+=ans[v];
    }
}
int main()
{
	cin>>n;
    f(i,1,n)
    {
        while(1)
        {
            x=in;
            if(!x) break;
            q.add(x,i);rd[i]++;
        }
    }
    tp();
    vis[0]=1;dfs(0);
    // f(i,1,n)
    // {
    //     cerr<<i<<":\n";
    //     f(j,0,3)
    //         cerr<<i<<" to "<<pow(2,j)<<" is "<<bz[i][j]<<endl;
    //     cerr<<endl;
    // }
    // f(i,0,n)
    // {
    //     cerr<<i<<":\n";
    //     F(p,i) cerr<<i<<" -> "<<v<<endl;
    // }
    f(i,1,n) printf("%d\n",ans[i]-1);
	return 0;
}