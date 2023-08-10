#include<bits/stdc++.h>
#define int long long
#define f(i,j,k) for(int i=j;i<=k;i++)
using namespace std;
const int mod=1e9+7;
int n,m,c,f[405];
int C[405][405];
int F(int x,int k)
{
    int ans=1;
    for(;k;x=x*x%mod,k>>=1)
        if(k&1) ans=ans*x%mod;
    return ans;
}
signed main()
{
	cin>>n>>m>>c;
	C[1][1]=1;
	f(i,0,400) C[i][i]=C[i][0]=1;
	f(i,2,400) f(j,1,i) C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
    f(i,1,c)
    {
        int ans=0;
        for(int j=m,cnt=1;j>=1;j--,cnt=mod-cnt)
            ans=(ans+C[m][j]*F(F(i+1,j)-1,n)%mod*cnt)%mod;
        f[i]=ans;
    }
    int ans=0;
    for(int i=c,cnt=1;i>=1;i--,cnt=mod-cnt)
        ans=(ans+C[c][i]*f[i]%mod*cnt)%mod;
    cout<<ans<<endl;
	return 0;
}