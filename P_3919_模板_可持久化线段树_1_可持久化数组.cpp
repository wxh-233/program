#include<bits/stdc++.h>
using namespace std;
int n,m;
int b[1000005];
int v,c,x,y;
struct tree{
	int l,r,cnt;
}e[100000005];
int xcnt=0;
int build(int l,int r)
{
	int X=++xcnt;
	if(l==r)
	{
		scanf("%d",&e[X].cnt);
		e[X].l=e[X].r=X;
		return X;
	}
	int mid=l+r>>1;
	e[X].l=build(l,mid);
	e[X].r=build(mid+1,r);
	e[X].cnt=e[e[X].l].cnt+e[e[X].r].cnt;
	return X;
}
int change(int k,int l,int r,int x,int y)
{
	int X=++xcnt;
	if(l==r)
	{
		e[X].cnt=y;
		return X;
	}
	int mid=l+r>>1;
	if(x<=mid)
	{
		int aaa=change(e[k].l,l,mid,x,y);
		e[X].l=aaa;
		e[X].r=e[k].r;
	}
	else
	{
		int aaa=change(e[k].r,mid+1,r,x,y);
		e[X].l=e[k].l;
		e[X].r=aaa;
	}
	e[X].cnt=e[e[X].l].cnt+e[e[X].r].cnt;
	return X;
}
int ask(int k,int l,int r,int x)
{
	if(l==r)
		return e[k].cnt;
	int mid=l+r>>1;
	if(x<=mid)
		return ask(e[k].l,l,mid,x);
	else
		return ask(e[k].r,mid+1,r,x);
	
}
int main()
{
	cin>>n>>m;
	b[0]=1;
	build(1,n);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&v,&c,&x);
		if(c==1)
		{
			scanf("%d",&y);
			b[i]=xcnt+1;
			change(b[v],1,n,x,y);
		}
		else
		{
			b[i]=b[v];
			printf("%d\n",ask(b[v],1,n,x));
		}
	}
	return 0;
}