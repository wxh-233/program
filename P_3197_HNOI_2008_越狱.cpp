#include<bits/stdc++.h>
#define int long long
#define mod 100003
using namespace std;
int n,m;
int pow(int a,int b,int k)
{
    int ans=1%k;
    int base=a%k;
    while(b)
    {
        if(b&1)
                ans=(ans*base)%k;
        base=(base*base)%k;
        b>>=1;
         
    }
    return ans;
} 
signed main()
{
	cin>>m>>n;
    int ans=pow(m,n,mod)-(m%mod*(pow(m-1,n-1,mod))%mod)%mod;
    while(ans<0) ans+=mod;
    ans%=mod;
    printf("%lld\n",ans);
	return 0;
}