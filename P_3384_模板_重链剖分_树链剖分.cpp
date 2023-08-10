#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace lsq {
	typedef int lsqxx;
	struct lq {
		struct lqbz {
			lsqxx v,nxt;
		}e[200005];
		lsqxx h[100005],cnt;
		void add(lsqxx u,lsqxx v) {
			e[++cnt].v=v;
			e[cnt].nxt=h[u];
			h[u]=cnt;
		}
#define F(z,u) for(int j=z.h[u],v=z.e[j].v;j;j=z.e[j].nxt,v=z.e[j].v)
	};
};
using namespace lsq;
lq q;
struct x_trees{
	struct{
		int l,r,sum,lan;
	}t[500005];
	void build(int k,int l,int r)
	{
		t[k].l=l;t[k].r=r;
		if(l==r) return;
		int mid=l+r>>1;
		build(k<<1,l,mid);
		build((k<<1)+1,mid+1,r);
	}
};
struct sum_x_trees:public x_trees{
	void down(int k)
	{
		t[k<<1].lan+=t[k].lan;
		t[k<<1].sum+=(t[k<<1].r-t[k<<1].l+1)*t[k].lan;
		t[(k<<1)+1].lan+=t[k].lan;
		t[(k<<1)+1].sum+=(t[(k<<1)+1].r-t[(k<<1)+1].l+1)*t[k].lan;
		t[k].lan=0;
	}
	void add(int k,int x,int y,int z)
	{
		if(t[k].l>y||t[k].r<x) return;
		if(t[k].l>=x&&t[k].r<=y)
		{
			t[k].sum+=(t[k].r-t[k].l+1)*z;
			t[k].lan+=z;
			return;
		}
		down(k);
		add(k<<1,x,y,z);
		add((k<<1)+1,x,y,z);
		t[k].sum=t[k<<1].sum+t[(k<<1)+1].sum;
	}
	int ask(int k,int x,int y)
	{
		if(t[k].l>y||t[k].r<x) return 0;
		if(t[k].l>=x&&t[k].r<=y) return t[k].sum;
		down(k);
		return ask(k<<1,x,y)+ask((k<<1)+1,x,y);
	}
}trees;
int n,m,r,p;
struct d{
	int num;
	int fa,d,big,siz;
	int xh,top;
}e[100005];
int fxh[100005],cntx;
void dfs1(int t)
{
	e[t].siz=1;
	F(q,t)
	{
		if(e[t].fa==v) continue;
		e[v].d=e[t].d+1;
		e[v].fa=t;
		dfs1(v);
		e[t].siz+=e[v].siz;
		if(e[e[t].big].siz<e[v].siz)
			e[t].big=v;
	}
}
void dfs2(int t)
{
	if(!t) return;
	e[t].xh=++cntx;
	trees.add(1,cntx,cntx,e[t].num);
	fxh[cntx]=t;
	if(e[e[t].fa].big==t) e[t].top=e[e[t].fa].top;
	else e[t].top=t;
	dfs2(e[t].big);
	F(q,t)
	{
		if(e[t].fa==v) continue;
		if(e[t].big==v) continue;
		dfs2(v);
	}
}
int op,x,y,z;
void change_line(int x,int y,int z)
{
	if(e[e[x].top].d<e[e[y].top].d) swap(x,y);
	if(e[e[x].top].d==e[e[y].top].d&&e[x].d<e[y].d) swap(x,y);
	if(e[x].top!=e[y].top)
	{
		trees.add(1,e[e[x].top].xh,e[x].xh,z);
		change_line(e[e[x].top].fa,y,z);
	}
	else
	{
		trees.add(1,e[y].xh,e[x].xh,z);
	}
}
int search_line(int x,int y)
{
	if(e[e[x].top].d<e[e[y].top].d) swap(x,y);
	if(e[e[x].top].d==e[e[y].top].d&&e[x].d<e[y].d) swap(x,y);
	if(e[x].top!=e[y].top)
	{
		return (trees.ask(1,e[e[x].top].xh,e[x].xh)+
			   search_line(e[e[x].top].fa,y))%p;
	}
	else
	{
		return trees.ask(1,e[y].xh,e[x].xh)%p;
	}
}
void change_tree(int x,int y)
{
	trees.add(1,e[x].xh,e[x].siz+e[x].xh-1,y);
}
int search_tree(int x)
{
	return trees.ask(1,e[x].xh,e[x].xh+e[x].siz-1)%p;
}
signed main()
{
	cin>>n>>m>>r>>p;
	trees.build(1,1,n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&e[i].num);
	for(int i=2;i<=n;i++)
		scanf("%lld%lld",&x,&y),q.add(x,y),q.add(y,x);
	e[r].fa=r;
	e[r].d=1;
	dfs1(r);
	dfs2(r);
	for(int i=1;i<=m;i++)
	{
		scanf("%lld",&op);
		if(op==1)
		{
			scanf("%lld%lld%lld",&x,&y,&z);
			change_line(x,y,z);
		}
		if(op==2)
		{
			scanf("%lld%lld",&x,&y);
			printf("%lld\n",search_line(x,y)%p);
		}
		if(op==3)
		{
			scanf("%lld%lld",&x,&y);
			change_tree(x,y);
		}
		if(op==4)
		{
			scanf("%lld",&x);
			printf("%lld\n",search_tree(x)%p);
		}
	}
	return 0;
}