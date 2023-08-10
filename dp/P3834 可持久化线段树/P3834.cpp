#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int x,y,z;
struct t{
    int l,r;
    int lx,rx;
    int num;
}t[1000005];int tcnt,root[2000005];
int make(int l=1,int r=1e14)
{
    int now=++tcnt;
    t[now].l=l;t[now].r=r;
    return now;
}
void build()
{
    root[0]=make();
}
void add(int late,int now,int x)
{
    int mid=t[late].l+t[late].r>>1;
    if(!t[late].lx) t[late].lx=make(t[late].l,mid);
    if(!t[late].rx) t[late].rx=make(mid+1,t[late].r);
    // cout<<t[now].l<<" "<<t[now].r<<endl;
    if(t[now].l==t[now].r)
    {
        t[now].num=t[late].num+1;
        // cout<<"??? "<<now<<" "<<t[now].num<<endl;
        return;
    }
    if(x<=mid)
    {
        t[now].rx=t[late].rx;
        if(!t[now].lx)
            t[now].lx=make(t[late].l,mid);
        add(t[late].lx,t[now].lx,x);
    }
    else
    {
        t[now].lx=t[late].lx;
        if(!t[now].rx)
            t[now].rx=make(mid+1,t[late].r);
        add(t[late].rx,t[now].rx,x);
    }
    // cout<<t[t[now].lx].num<<" "<<t[t[now].rx].num<<endl;
    t[now].num=t[t[now].lx].num+t[t[now].rx].num;
}
int ask(int k1,int k2,int x)
{
    // cout<<t[k1].l<<" and "<<t[k1].r<<endl;
    if(t[k1].l==t[k1].r) return t[k1].l;
    int cnt=t[t[k1].lx].num-t[t[k2].lx].num;
    // cout<<cnt<<" "<<x<<endl;
    if(cnt>=x)
        return ask(t[k1].lx,t[k2].lx,x);
    else
        return ask(t[k1].rx,t[k2].rx,x-cnt);
}
signed main()
{
	cin>>n>>m;
    build();
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&x);
        root[i]=make();
        add(root[i-1],root[i],x);
        // cout<<endl;
        // cout<<t[t[root[i]].lx].num<<" to "<<t[t[root[i]].rx].num<<endl;cout<<endl;
    }
    for(int i=1;i<=m;i++)
    {
        scanf("%lld%lld%lld",&x,&y,&z);
        printf("%lld\n",ask(root[y],root[x-1],z));
        // cout<<t[root[y]].num<<" to "<<t[root[x-1]].num<<endl;
        // cout<<endl;
    }
	return 0;
}