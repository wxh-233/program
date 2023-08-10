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
int w[105],c[105];
int dp[105][1005];//dp[i][j]查到第i位，容量为j，最大价值
int ans=0;
int main()
{
	cin>>m>>n;
    f(i,1,n) w[i]=in,c[i]=in;
    f(i,1,n) f(j,1,m) dp[i][j]=max(j>=w[i]?dp[i-1][j-w[i]]+c[i]:0,dp[i-1][j]);
    f(i,1,m) ans=max(ans,dp[n][i]);
    cout<<ans<<endl;
	return 0;
}