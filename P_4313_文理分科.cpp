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
    }q;
};
using namespace lsq;
int n,m,s=0,t=1,cnt;
int art[505][505],science[505][505];
int same_art[505][505],same_science[505][505];
int d[1000005];
int dcnt=0;
int now[1000005];
const int INF=1e15;
bool bfs()
{
    queue<int>qu;
    memset(d,0,sizeof(d));
    d[s]=1;now[s]=q.h[s];
    qu.emplace(s);
    while(!qu.empty())
    {
        int u=qu.front();
        qu.pop();
        for(int i=q.h[u],y;i;i=q.e[i].nxt)
            if(q.e[i].w&&!d[y=q.e[i].v])
            {
                now[y]=i;
                d[y]=d[u]+1;
                qu.emplace(y);
                if(y==t)return true;
            }
    }
    return false;
}
int dinic(int x,int flow)
{
    if(x==t)return flow;
    int res=flow;
    for(int i=q.h[x],y;i&&res;i=q.e[i].nxt)
    {
        now[x]=i;
        if(q.e[i].w&&d[y=q.e[i].v]==d[x]+1)
        {
            int t=dinic(y,min(q.e[i].w,res));
            if(!t)d[y]=0;
            res-=t;q.e[i].w-=t;q.e[i^1].w+=t;
        }
    }
    return flow-res;
}
int two_one(int x,int y)
{
    return (x-1)*m+y+1;
}
int ans=0;
signed main()
{
    cin>>n>>m;
    dcnt=n*m*2+2;
    cnt=n*m+5;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            scanf("%lld",&art[i][j]);
            ans+=art[i][j];
        }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            scanf("%lld",&science[i][j]);
            ans+=science[i][j];
        }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            scanf("%lld",&same_art[i][j]);
            ans+=same_art[i][j];
        }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            scanf("%lld",&same_science[i][j]);
            ans+=same_science[i][j];
        }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            q.add(s,two_one(i,j),art[i][j]);
            q.add(two_one(i,j),s,0);
            q.add(two_one(i,j),t,science[i][j]);
            q.add(t,two_one(i,j),0);
            int dx[5]={0,1,0,-1,0};
            int dy[5]={0,0,1,0,-1};
            q.add(s,++cnt,same_art[i][j]);
            q.add(cnt,s,0);
            q.add(cnt,two_one(i,j),INT_MAX);
            q.add(two_one(i,j),cnt,0);
            for(int k=1;k<=4;k++)
            {
                int xx=i+dx[k],yy=j+dy[k];
                if(xx<1||yy<1||xx>n||yy>m) continue;
                q.add(cnt,two_one(xx,yy),INT_MAX);
                q.add(two_one(xx,yy),cnt,0);
            }
            ++cnt;
            q.add(cnt,t,same_science[i][j]);
            q.add(t,cnt,0);
            q.add(two_one(i,j),cnt,INT_MAX);
            q.add(cnt,two_one(i,j),0);
            for(int k=1;k<=4;k++)
            {
                int xx=i+dx[k],yy=j+dy[k];
                if(xx<1||yy<1||xx>n||yy>m) continue;
                q.add(two_one(xx,yy),cnt,INT_MAX);
                q.add(cnt,two_one(xx,yy),0);
            }
        }
    int res,maxn=0;
    while(bfs())while(res=dinic(s,INF))maxn+=res;
    cout<<ans-maxn;
    return 0;
}