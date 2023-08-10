#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace wxh666{
    #define getchar getchar_unlocked
    #define putchar putchar_unlocked
    #define f(a,b,c) for(int a=b;a<=c;a++)
    inline int read()
    {
        char ch=getchar();int f=1,ans=0;
        for(;!isdigit(ch);ch=getchar()) ch=='-'?f=-1:f=1;
        for(;isdigit(ch);ch=getchar()) ans=(ans<<3)+(ans<<1)+(ch&15);
        return f*ans;
    }
    #define in read()
};using namespace wxh666;
const int inf=1e18-7;
int n;
int d[455];
int dp[455][455][2];
void dfs(int t)
{
    dp[t][0][0]=dp[t][1][1]=0;
    dp[t][0][1]=dp[t][1][0]=-inf;
    int s1=0,s2=0;
    f(i,2,n/2) dp[t][i][0]=dp[t][i][1]=-inf;
    if((t<<1)<=n) dfs(s1=(t<<1));
    if((t<<1|1)<=n) dfs(s2=(t<<1|1));
    if(!s1) return;
    if(!s2)
    {
        dp[t][2][1]=d[s1];
        dp[t][0][0]=d[s1];
        return;
    }
    f(i,0,n/2)
    {
        f(j,0,i)
            dp[t][i][0]=max(dp[t][i][0],max(
                max(
                dp[s1][j][1]+dp[s2][i-j][0]+d[s2],
                dp[s1][j][0]+dp[s2][i-j][1]+d[s1]
            ),
                max(
                dp[s1][j][1]+dp[s2][i-j][1],
                dp[s1][j][0]+dp[s2][i-j][0]+d[s1]+d[s2]
            )));
        f(j,0,i-1)
            dp[t][i][1]=max(dp[t][i][1],max(
                max(
                dp[s1][j][1]+dp[s2][i-j-1][0]+d[s1],
                dp[s1][j][0]+dp[s2][i-j-1][1]+d[s2]
            ),
                max(
                dp[s1][j][0]+dp[s2][i-j-1][0],
                dp[s1][j][1]+dp[s2][i-j-1][1]+d[s1]+d[s2]
            )));
    }
}
signed main()
{
    cin>>n;
    f(i,1,n) d[i]=in;dfs(1);
    cout<<max(dp[1][n/2][1],dp[1][n/2][0])<<endl;
    return 0;
}