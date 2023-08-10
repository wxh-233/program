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
        for(int j=1;j<=m;j++)\
            printf("%.3lf ",dt[i][j]);\
        cout<<endl;\
    }
};using namespace wxh666;
int n;
double a[105][105];
void Gauss_Jordan()
{
    f(i,1,n)
    {
        int cnt=1;
        xxx:double me=a[i][i];
        if(cnt+i>n+1) printf("No Solution\n"),exit(0);
        if(me==0) {swap(a[i],a[i+(cnt++)]);goto xxx;}
        f(j,1,n+1) a[i][j]/=me;
        f(j,1,n)
        {
            if(i==j) continue;
            double fx=a[j][i];
            f(k,1,n+1)
                a[j][k]=a[j][k]-a[i][k]*fx;
        }
    }
}
int main()
{
	cin>>n;
    f(i,1,n) f(j,1,n+1) scanf("%lf",&a[i][j]);
    Gauss_Jordan();
    f(i,1,n) if(!a[i][i]) printf("No Solution\n");
    f(i,1,n) printf("%.2lf\n",a[i][n+1]);
	return 0;
}