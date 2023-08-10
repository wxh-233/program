#include<bits/stdc++.h>
#define getchar getchar_unlocked
#define putchar putchar_unlocked
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
    }p;
};
using namespace lsq;
int T;
int n,m;
int x,y;
int rd[1000005];
stack<int>ans;
void tp()
{
    priority_queue<int>q;
    for(int i=1;i<=n;i++) if(!rd[i]) q.push(i);
    while(!q.empty())
    {
        int u=q.top();q.pop();ans.push(u);
        F(p,u) if(!(--rd[v])) q.push(v);
    }
    if(ans.size()!=n) printf("Impossible!");
    else while(!ans.empty()) printf("%d ",ans.top()),ans.pop();putchar('\n');
}
int main()
{
	cin>>T;
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d",&y,&x);
            p.add(x,y);
            rd[y]++;
        }
        tp();
        while(!ans.empty()) ans.pop();p.erase(); for(int i=1;i<=n;i++) rd[i]=0;
    }
	return 0;
}