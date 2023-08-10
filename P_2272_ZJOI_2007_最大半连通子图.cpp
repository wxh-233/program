#include<bits/stdc++.h>
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#define f(a,b,c) for(int a=b;a<=c;a++)
using namespace std;
namespace lsq {
    typedef int lsqxx;
    struct lq {
        struct lqbz {
            lsqxx v,w,nxt;
        } e[2000005];
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
int n,m,mod;
int x,y;
int vis[1000005];
int dis[1000005];
int scc,bs[1000005],sz[1000005];
int dfn[1000005],low[1000005],dfns;
stack<int>s;
string xx,yy;
void tarjan(int t)
{
    low[t]=dfn[t]=++dfns;s.push(t);vis[t]=dis[t]=1;
    F(q,t)
    {
        if(!dfn[v]) tarjan(v),low[t]=min(low[t],low[v]);
        else if(dis[v]) low[t]=min(low[t],dfn[v]);
    }
    if(dfn[t]==low[t])
    {
        ++scc;int k;
        do{
            bs[k=s.top()]=scc;++sz[scc];
            dis[k]=0;s.pop();
        }while(k!=t);
    }
}
int rd[1000005],cd[1000005];
int ans1,ans2;
int len[100005],dp[100005];
void tp()
{
    queue<int>h;
    f(i,1,scc) len[i]=sz[i];
    f(i,1,scc) if(!rd[i]) dp[i]=1,h.push(i);
    while(!h.empty())
    {
        int now=h.front();h.pop();
        F(p,now)
        {
            if(len[v]<len[now]+sz[v])
            {
                len[v]=len[now]+sz[v];
                dp[v]=dp[now]%mod;
            }
            else
            {
                if(len[v]==len[now]+sz[v])
                    dp[v]=(dp[v]+dp[now])%mod;
            }
            rd[v]--;
            if(!rd[v]) h.push(v);
        }
    }
}
map<vector<int>,int>ggg;
int main()
{
	cin>>n>>m>>mod;
    f(i,1,m) scanf("%d%d",&x,&y),q.add(x,y);
    f(i,1,n) if(!dfn[i]) tarjan(i);
    f(i,1,n)
    {
        F(q,i)
        {
            vector<int>gg;
            gg.push_back(bs[i]);
            gg.push_back(bs[v]);
            if(bs[i]!=bs[v])
            if(!ggg[gg])
                    ggg[gg]=1,
                    p.add(bs[i],bs[v]),
                    ++rd[bs[v]],++cd[bs[i]];
                    // cerr<<i<<" "<<v<<" is "<<bs[i]<<" to "<<bs[v]<<endl;
        }
    }
    tp();
    f(i,1,scc) ans1=max(ans1,len[i]);
    f(i,1,scc) if(len[i]==ans1) ans2=(ans2+dp[i])%mod;
    // f(i,1,scc) cerr<<dp[i]<<" ";cerr<<endl;
    // f(i,1,scc) cerr<<len[i]<<" ";
    cout<<ans1<<endl<<ans2<<endl;
	return 0;
}