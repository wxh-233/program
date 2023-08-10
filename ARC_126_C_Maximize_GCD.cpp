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
int n,k,a[300005],t[300005],sum;
int ans;
signed main()
{
	cin>>n>>k;
    f(i,1,n) scanf("%lld",&a[i]),t[a[i]]++,sum+=a[i];
    sort(a+1,a+1+n);
    f(i,1,a[n]) t[i]+=t[i-1];
    if(a[n]*n-sum<=k)
    {
        k-=a[n]*n-sum;
        cout<<a[n]+k/n<<endl;
        return 0;
    }
    for(int i=a[n];i>1;i--)
    {
        ans=0;
        for(int j=i;j-i<a[n];j+=i)
            ans+=(((j<=a[n])?t[j]:n)-t[j-i])*j;
        ans-=sum;
        if(ans<=k)
        {
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<"1\n";
	return 0;
}