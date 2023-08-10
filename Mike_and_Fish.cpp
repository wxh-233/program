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
    }q;
};
using namespace lsq;
int n,vis[1000005];
int su[1000005],sv[1000005];
int x,y;
int a[1000005];
void dfs(int t,int cnt)
{
    vis[t]=cnt;
    F(q,t) if(vis[v]==-1) dfs(v,cnt^1);
}
int main()
{
	cin>>n;f(i,1,n) vis[i]=-1;
    f(i,1,n)
    {
        scanf("%d%d",&x,&y);
        if(su[x])
            q.add(su[x],i),q.add(i,su[x]),su[x]=0;
        else su[x]=i;
        if(sv[y])
            q.add(sv[y],i),q.add(i,sv[y]),sv[y]=0;
        else sv[y]=i;
    }
    f(i,1,n) if(vis[i]==-1) dfs(i,0);
    f(i,1,n) printf("%c",(vis[i])?'r':'b');
	return 0;
}