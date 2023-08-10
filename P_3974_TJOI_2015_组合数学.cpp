#include<bits/stdc++.h>
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#define f(a,b,c) for(int a=b;a<=c;a++)
using namespace std;
int T,n,m;
int a[1005][1005];
int dp[1005][1005];
int main()
{
    cin>>T;
    while(T--)
    {
        f(i,1,n) f(j,1,m) dp[i][j]=0;
        scanf("%d%d",&n,&m);
        f(i,1,n) f(j,1,m) scanf("%d",&a[i][j]);
        f(i,1,n) for(int j=m;j>=1;j--)
            dp[i][j]=max(max(dp[i-1][j],dp[i][j+1]),dp[i-1][j+1]+a[i][j]);
        printf("%lld\n",dp[n][1]);
    }
    return 0;
}