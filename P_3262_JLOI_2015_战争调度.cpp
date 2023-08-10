#include<bits/stdc++.h>
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#define f(a,b,c) for(int a=b;a<=c;a++)
using namespace std;
int read()
{
    char ch=getchar();int f=1,ans=0;
    for(;ch<'0'||ch>'9';ch=getchar()) ch=='-'?f=-1:f=1;
    for(;ch>='0'&&ch<='9';ch=getchar()) ans=(ans<<3)+(ans<<1)+(ch&15);
    return f*ans;
}
#define in read()
int n,m;
int dp[2048][2048];
int w[1024][15],f[1024][15];
int vis[10];
void dfs(int k,int c)
{
    f(i,0,1<<c) dp[k][i]=0;
    if(!c)
    {
        f(i,1,n)
            if(!vis[i]) dp[k][0]+=f[k][i];
            else dp[k][1]+=w[k][i];
        return;
    }
    f(x,0,1)
    {
        vis[c]=x;
        dfs(k<<1,c-1); dfs(k<<1|1,c-1);
        f(i,0,(1<<c-1)) f(j,0,(1<<c-1))
            dp[k][i+j]=max(dp[k][i+j],dp[k<<1][i]+dp[k<<1|1][j]);
    }
}
int ans;
int main()
{
	n=in,m=in;n--;
    f(i,1<<n,(1<<n+1)-1) f(j,1,n) w[i][j]=in;
    f(i,1<<n,(1<<n+1)-1) f(j,1,n) f[i][j]=in;
    dfs(1,n);
    f(i,0,m) ans=max(ans,dp[1][i]);
    printf("%d\n",ans);
	return 0;
}