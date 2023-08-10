#include<bits/stdc++.h>
#define int long long
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
const int mod=20100403;
int n,m;
int fpow(int x,int k,int p=INT_MAX)
{
    int ans=1;
    while(k)
    {
        if(k&1) ans=ans*x%p;
        x=x*x%p;k>>=1;
    }
    return ans;
}
int C(int n,int m)
{
    int a=1;
    f(i,2,n) a=(a*i)%mod;
    int b=1;
    f(i,2,m) b=(b*i)%mod;
    int c=1;
    f(i,2,n-m) c=(c*i)%mod;
    b=(b*c)%mod;
    int d=fpow(b,mod-2,mod);
    return (a*d)%mod;
}
signed main()
{
    cin>>n>>m;
    cout<<(C(n+m,m)-C(n+m,m-1)+mod)%mod;
	return 0;
}
//https://www.luogu.com.cn/blog/user35379/solution-p1641