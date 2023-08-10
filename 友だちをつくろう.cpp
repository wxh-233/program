#include<bits/stdc++.h>
#define int long long
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#define f(a,b,c) for(int a=b;a<=c;a++)
using namespace std;
int n,m;
int x,y;
int a[100005];
int d[100005];
int f[100005],r[100005];
int getfa(int x)
{
    if(f[x]==x) return x;
    else return f[x]=getfa(f[x]);
}
bool search(int x,int y)
{
    x=getfa(x);y=getfa(y);
    if(x==y) return false;
    f[y]=x; r[x]+=r[y]; return true;
}
void change(int x)
{
    if(a[x]&&search(x,a[x])) change(a[x]);
}
int ans;
signed main()
{
	cin>>n>>m;
    f(i,1,n) f[i]=i,r[i]=1;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&x,&y); ++d[x];
        if(a[x]) search(a[x],y);
        else a[x]=y;
    }
    f(i,1,n) if(r[getfa(i)]>1&&a[i]) change(i);
    f(i,1,n) if(f[i]==i) ans+=1ll*r[i]*(r[i]-1);
    f(i,1,n) if(a[i]&&getfa(i)!=getfa(a[i])) ans+=d[i];
    cout<<ans<<endl;
	return 0;
}