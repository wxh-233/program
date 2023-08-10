#include<bits/stdc++.h>
#define int long long
#define f(i,j,k) for(int i=j;i<=k;i++)
using namespace std;
const int mod=1e9+7;
int n,m;
int a[1005];
int c[3005][3005];
int ans;
signed main()
{
	cin>>n>>m;
	f(i,1,m) int l=scanf("%lld",&a[i]);
	c[1][1]=1;
	f(i,0,3000) c[i][i]=c[i][0]=1;
	f(i,2,3000) f(j,1,i) c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
	f(i,0,n-1)
	{
		int t=1;
		f(j,1,m)
			t=((t%mod)*(c[n-i+a[j]-1][n-i-1]%mod))%mod;
		if(i&1) ans=(ans-t*c[n][i]%mod+mod)%mod;
		else ans=(ans+t*c[n][i]%mod)%mod;
	}
	cout<<ans%mod;
	return 0;
}
