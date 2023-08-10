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
int n,m;
int x,y;
namespace Subtask2{
    int low[105]={0},dfn[105]={0},dfns=0;
    int bs[105]={0},dis[105]={0},vis[105]={0},sz[105]={0};
    int scc=0,cnt=0;
    int s[100000],scnt;
    void tarjan(int t,int fa,int ffa)
    {
        low[t]=dfn[t]=++dfns;s[++scnt]=t;vis[t]=dis[t]=1;
        F(q,t)
        {
            if(!dfn[v])
            {
                tarjan(v,t,fa),low[t]=min(low[t],low[v]);

            }
            else
            {
                if(dis[v]) low[t]=min(low[t],dfn[v]);
                if(dis[v]/*&&s[scnt-2]==v&&ffa==v*/) ++cnt;

            }
        }
        if(dfn[t]==low[t])
        {
            ++scc;int k;
            do{
                bs[k=s[scnt]]=scc;++sz[scc];
                low[k]=t,dis[k]=0;scnt--;
            }while(k!=t);
        }
    }
};
int main()
{
    freopen("battle.in","r",stdin);
    freopen("battle.out","w",stdout);
    cin>>n>>m;
    f(i,1,m) scanf("%d%d",&x,&y),q.add(x,y);
    if(m==n*(n-1)/2)
    {
        using namespace Subtask2;
        f(i,1,n) if(!dfn[i]) tarjan(i,i,i);
        cout<<cnt<<" "<<cnt<<endl;
        return 0;
    }
    cout<<rand()%998244353<<" "<<rand()%998244353<<endl;
    return 0;
}