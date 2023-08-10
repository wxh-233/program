#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
struct wxh666{
    int a,b;
}a[2005];
int n,h;
int dp[2005];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        scanf("%d%d",&a[i].a,&a[i].b); cin>>h;
    sort(a+1,a+1+n,[&](auto x,auto y){return x.a+x.b<y.a+y.b;});
    for(int i=1;i<=n;i++) dp[i]=-inf,dp[0]+=a[i].a;
    for(int i=1;i<=n;i++)
        for(int j=i;j>=1;j--)
            if(dp[j-1]+a[i].b>=h)
                dp[j]=max(dp[j],dp[j-1]-a[i].a);
    for(int i=n;i>=0;i--) if(dp[i]>=0) printf("%d",i),exit(0);
    return 0;
}