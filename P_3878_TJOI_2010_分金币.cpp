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
            printf("%lld ",dt[i][j]);\
        cout<<endl;\
    }
};using namespace wxh666;
int t,n;
int v[100005];
int lsum,rsum,ans=0x7f7f7f7f;
void mori_th()
{
    int cnt=0x7f7f7f7f;
    for(double T=10000;T>=0.0001;T*=0.9998)
    {
        int l=rand()%(n/2)+1;
        int r=rand()%((n+1)/2)+n/2+1;
        lsum-=v[l],lsum+=v[r];
        rsum-=v[r],rsum+=v[l];
        if(abs(lsum-rsum)<cnt) cnt=abs(lsum-rsum),ans=min(ans,cnt),swap(v[l],v[r]);
        else
        {
            if(abs(lsum-rsum)/T<rand()*1.0/RAND_MAX)
                cnt=abs(lsum-rsum),swap(v[l],v[r]);
            else lsum+=v[l],lsum-=v[r],
                rsum+=v[r],rsum-=v[l];
        }
    }
}
signed main()
{
    srand(time(0));
	cin>>t;
    while(t--)
    {
        scanf("%lld",&n);
        f(i,1,n) scanf("%lld",&v[i]);
        if(n==1) {printf("%d\n",v[1]);continue;}
        f(i,1,n/2) lsum+=v[i];
        f(i,n/2+1,n) rsum+=v[i];
        mori_th();
        cout<<ans<<endl;
        lsum=rsum=0;
        ans=0x7f7f7f7f;
    }
	return 0;
}