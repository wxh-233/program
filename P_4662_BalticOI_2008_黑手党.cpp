#include<bits/stdc++.h>
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
    }q;
};using namespace lsq;
int n,m;
int s,t;
int x,y;
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
    while(d[s]<2*n)
        ans+=dfs();
    return ans;
}
int ans[205];
void END(int t)
{
    ans[((t+1)>>1)]++;
    F(q,t)
    {
        if(w>0&&d[t]>d[v])
            END(v);
    }
}
int main()
{
	cin>>n>>m;
    cin>>s>>t;
    s=s*2-1;t=t*2;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        q.add(i*2-1,i*2,x);
        q.add(i*2,i*2-1,0);
    }
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&x,&y);
        q.add(x*2,y*2-1,INT_MAX);
        q.add(y*2-1,x*2,0);

        q.add(x*2-1,y*2,0);
        q.add(y*2,x*2-1,INT_MAX);
    }
    ISAP();
    END(s);
    for(int i=1;i<=n;i++)
        if(ans[i]==1)
            printf("%d ",i);
	return 0;
}