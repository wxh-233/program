//ISAP
#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace lsq {
    typedef int lsqxx;
    struct lq {
        struct lqbz {
            lsqxx v,w,nxt;
        } e[1000005];
        lsqxx h[1000005],cnt=1;
        inline void add(lsqxx u,lsqxx v,lsqxx w=1) {
            e[++cnt].v=v;
            e[cnt].w=w;
            e[cnt].nxt=h[u];
            h[u]=cnt;
        }
    #define F(z,u) for(int j=z.h[u],v=z.e[j].v,w=z.e[j].w;j;j=z.e[j].nxt,v=z.e[j].v,w=z.e[j].w)
    }q,p;
};using namespace lsq;
int n,m,s,t;
int x,y,z;
int d[205];
int dfs(int u=s,int in=INT_MAX)
{
    if(u==t) return in;
    int out=0;
    F(q,u)
    {
        if(d[u]>d[v]&&w)
        {
            int nt=dfs(v,min(w,in));
            in-=nt;out+=nt;
            q.e[j].w-=nt;q.e[j^1].w+=nt;
            if(!in) return out;
        }
    }
    ++d[u];
    return out;
}
int ISAP()
{
    int ans=0;
    while(d[s]<n)
        ans+=dfs();
    return ans;
}
signed main()
{
	cin>>n>>m>>s>>t;
    for(int i=1;i<=m;i++)
    {
        int _=scanf("%lld%lld%lld",&x,&y,&z);
        if(x==y) continue;
        q.add(x,y,z),q.add(y,x,0),p.add(y,x,z);
    }
    cout<<ISAP();
	return 0;
}