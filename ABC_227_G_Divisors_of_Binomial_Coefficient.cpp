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
const int mod=998244353;
int n,k;
int now[1000005];
int h[1000005];
int ans=1;
signed main()
{
    cin>>n>>k;
    f(i,1,k) now[i]=i;
    f(i,2,1e6)
        for(int j=i;j<=k;j+=i)
            while(now[j]%i==0) now[j]/=i,h[i]--;
    f(i,1,k) now[i]=n-k+i;
    f(i,2,1e6)
        for(int j=((n-k)/i+1)*i;j<=n;j+=i)
            while(now[j+k-n]%i==0) now[j+k-n]/=i,h[i]++;
    f(i,1,1e6) ans=ans*(h[i]+1)%mod;
    f(i,1,k) if(now[i]!=1) ans=(ans*2%mod);
    cout<<ans<<endl;
	return 0;
}
