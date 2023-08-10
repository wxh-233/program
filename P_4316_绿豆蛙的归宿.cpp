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
int x,y,z;
int cd[100005],rd[100005];
double dis[100005],qz[100005];
void TP(int t)
{
    F(q,t)
    {
        dis[v]+=dis[t]*(1.0/cd[t])+w*(1.0/cd[t])*qz[t];
        qz[v]+=qz[t]*(1.0/cd[t]);
        --rd[v];
        if(!rd[v])
            TP(v);
    }
}
int main()
{
	cin>>n>>m;
    for(int _=1;_<=m;_++)
    {
        int l=scanf("%d%d%d",&x,&y,&z);
        q.add(x,y,z); ++cd[x]; ++rd[y];
    }
    qz[1]=1;
    TP(1);
    printf("%.2lf",dis[n]);
	return 0;
}