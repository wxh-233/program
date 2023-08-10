#include<bits/stdc++.h>
using namespace std;
namespace wxh666{
    #define getchar getchar_unlocked
    #define putchar putchar_unlocked
    #define sqrt(a) __builtin_sqrt(a)
    #define f(a,b,c) for(int a=b;a<=c;a++)
    inline int read()
    {
        char ch=getchar();int f=1,ans=0;
        for(;!isdigit(ch);ch=getchar()) ch=='-'?f=-1:f=1;
        for(;isdigit(ch);ch=getchar()) ans=(ans<<3)+(ans<<1)+(ch&15);
        return f*ans;
    }
    #define in read()
    #define cs(dt,n,m) \
    for(int i=1;i<=n;i++)\
    {\
        for(int j=1;j<=n;j++)\
            printf("%d ",dt[i][j]);\
        cout<<endl;\
    }
};using namespace wxh666;
int n,m;
const int mod=20100403;
namespace pts_30{
    int dp[2005][2005];
    void dps()
    {
        dp[0][0]=1;
        f(i,1,n+m)
            f(j,0,min(i/2,m))
                if(j>0) dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%mod;
                else dp[i][j]=dp[i-1][j]%mod;
        cout<<dp[n+m][m]<<endl;
    }
};
namespace pts_100{
    int dp[1000005];
    void dps()
    {
        dp[0]=1;
        f(i,1,n+m)
            for(int j=min(i/2,m);j>=0;j--)
                if(j>0) dp[j]=(dp[j-1]+dp[j])%mod;
                else dp[j]=dp[j]%mod;
        cout<<dp[m];
    }
};
int main()
{
    // freopen("string.in","r",stdin);
    // freopen("string.out","w",stdout);
    cin>>n>>m;
    if(n<=1000&&m<=1000)
    {
        using namespace pts_30;
        dps();
        return 0;
    }
    using namespace pts_100;
    dps();
    return 0;
}
/*
4*3/2/1
*/