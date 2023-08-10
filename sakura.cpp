#include<bits/stdc++.h>
using namespace std;
int type,n,m,p;
int dp[2005][1005][2];
int jc[2005];
void init()
{
    jc[1]=1;
    for(int i=2;i<=n;i++)
        jc[i]=(jc[i-1]*(i%p))%p;
}
int main()
{
    cin>>type>>n>>m>>p;
    init();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            dp[i][j][0]=(dp[i-1][j][0]+dp[i-1][j][1])%p,
            dp[i][j][1]=dp[i-1][j-1][0]%p;
    printf("%d\n",(jc[m]*((dp[n][m][1]+dp[n][m][0])%p))%p);
    return 0;
}
/*
dp[i][0/1]
*/