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
int n,k=1,cnt;
int prime[205]={0,2};
int ans[1005],anss=1;
signed main()
{
	cin>>n;
	if(n==1) {puts("1");return 0;}
	for(int i=3;i<=n;i+=2)
	{
		prime[++k]=i;
		f(j,2,k-1) if(!(i%prime[j])){k--;break;}
	}
	ans[0]=1;
	f(i,1,k) for(int j=n;j>=prime[i];j--)
	{
		cnt=prime[i];
		while(cnt<=j)
		{
			ans[j]+=ans[j-cnt];
			cnt*=prime[i];
		}
	}
	f(i,1,n) anss+=ans[i];
	printf("%lld\n",anss);
	return 0;
}