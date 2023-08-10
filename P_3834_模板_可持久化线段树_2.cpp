#include<bits/stdc++.h>
#define getchar getchar_unlocked
#define putchar putchar_unlocked
using namespace std;
struct tree{
	int l,r,x,y,num;
}t[6400005];int cnt;
int n,m;
int a,l,r,k;
int root[6400005];
int make(int l,int r)
{
	t[++cnt].l=l;t[cnt].r=r;
	return cnt;
}
void add(int late,int now,int x,int y,int z)
{
	if(x==y)
	{
		t[now].num=t[late].num+1;
		return;
	}
	int mid=x+y>>1;
	if(z<=mid)
	{
		t[now].x=make(x,mid);
		t[now].y=t[late].y;
		add(t[late].x,t[now].x,x,mid,z);
	}
	else
	{
		t[now].y=make(mid+1,y);
		t[now].x=t[late].x;
		add(t[late].y,t[now].y,mid+1,y,z);
	}
	t[now].num+=t[t[now].x].num+t[t[now].y].num;
}
int ask(int kk,int k,int l,int r,int x)
{
	if(l==r) return l;
	int mid=l+r>>1;
	if(x<=t[t[k].x].num-t[t[kk].x].num)
		return ask(t[kk].x,t[k].x,l,mid,x);
	else
		return ask(t[kk].y,t[k].y,mid+1,r,x-t[t[k].x].num+t[t[kk].x].num);
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a);
		root[i]=make(-1e9,1e9);
		add(root[i-1],root[i],-1e9,1e9,a);
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&l,&r,&k);
		printf("%d\n",ask(root[l-1],root[r],-1e9,1e9,k));
	}
	return 0;
}