#include<bits/stdc++.h>
using namespace std;
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
    #define F(z,u) for(int j=z.h[u],v=z.e[j].v,w=z.e[j].w;j;j=z.e[j].nxt,v=z.e[j].v,w=z.e[j].w)
    }q;
};
using namespace lsq;
int n,m;
int x,y;
int color[10005];
int cnt[2];
int ans;
void dfs(int t,int c)
{
    F(q,t)
    {
        if(color[v]!=-1)
        {
            if(color[v]!=c)
            {
                cout<<"Impossible\n";
                exit(0);
            }
            continue;
        }
        color[v]=c;
        cnt[c]++;
        dfs(v,c^1);
    }
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int l=scanf("%d%d",&x,&y);
        q.add(x,y);
        q.add(y,x);
    }
    for(int i=1;i<=n;i++) color[i]=-1;
    for(int i=1;i<=n;i++)
    {
        if(color[i]!=-1) continue;
        cnt[0]=cnt[1]=0;
        color[i]=1;
        cnt[1]++;
        dfs(i,0);
        ans+=min(cnt[0],cnt[1]);
    }
    cout<<ans<<endl;
	return 0;
}