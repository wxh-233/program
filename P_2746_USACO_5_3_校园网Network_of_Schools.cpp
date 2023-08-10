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
int read()
{
    char ch=getchar();int f=1,ans=0;
    for(;ch<'0'||ch>'9';ch=getchar()) ch=='-'?f=-1:f=1;
    for(;ch>='0'&&ch<='9';ch=getchar()) ans=(ans<<3)+(ans<<1)+(ch&15);
    return f*ans;
}
using namespace lsq;
int n;
int x;
int vis[100005];
int dis[100005];
int scc,bs[100005],sz[100005];
int dfn[100005],low[100005],dfns;
stack<int>s;
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
int rd[100005],cd[100005];
int ans,cnt1,cnt2;
int main()
{
	cin>>n;
    f(i,1,n) while(1)
    {
        scanf("%d",&x);
        if(x==i) continue;
        if(x==0) break;
        q.add(i,x);
    }
    f(i,1,n) if(!vis[i]) tarjan(i);
    f(i,1,n) F(q,i)
    {
        if(bs[i]==bs[v]) continue;
        cd[bs[i]]++;rd[bs[v]]++;
    }
    if(scc==1)
    {
        cout<<1<<endl<<0<<endl;return 0;
    }
    f(i,1,scc)
    {
        if(rd[i]==0) cnt1++;
        if(cd[i]==0) cnt2++;
    }
    ans=max(cnt1,cnt2);
    cout<<cnt1<<endl;
    cout<<ans<<endl;
	return 0;
}