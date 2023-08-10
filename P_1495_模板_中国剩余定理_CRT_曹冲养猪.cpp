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
int n;
int a[15],b[15];
unsigned long long sum=1,ans,t[15];
signed main()
{
	cin>>n;
    f(i,1,n) a[i]=in,b[i]=in,sum*=a[i];
    f(i,1,n) t[i]=sum/a[i];
    f(i,1,n) for(unsigned long long j=t[i];j<=0x7f7f7f7f7f7f;j+=t[i])
        if(j%a[i]==1) {ans+=j*b[i]%sum;break;}
    cout<<ans%sum<<endl;
	return 0;
}