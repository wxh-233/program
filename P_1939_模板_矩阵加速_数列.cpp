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
	// #define in read()
};using namespace wxh666;
namespace matrixs{
    int matrixs_mod=2147483647;
    struct matrix{
        int a[105][105]={0};
        int n=0,m=0;
        void in(int x=-1,int y=-1)
        {
            if(x==-1) scanf("%lld",&x);
            if(y==-1) scanf("%lld",&y);
            n=x,m=y;
            f(i,1,n) f(j,1,m) scanf("%lld",&a[i][j]);
        }
        void out()
        {
            f(i,1,n)
            {
                f(j,1,m) printf("%lld ",a[i][j]);
                putchar('\n');
            }
        }
    };
    matrix operator +(matrix x,matrix y)
    {
        matrix ans={0};ans.n=x.n;ans.m=x.m;
        f(i,1,ans.n) f(j,1,ans.m) ans.a[i][j]=x.a[i][j]+y.a[i][j];
        return ans;
    }
    matrix operator *(matrix x,matrix y)
    {
        matrix ans={0};memset(ans.a,0,sizeof(ans.a));
        ans.n=x.n;ans.m=y.m;
        f(i,1,ans.n) f(j,1,ans.m) f(k,1,x.m) ans.a[i][j]+=x.a[i][k]*y.a[k][j],ans.a[i][j]%=matrixs_mod;
        return ans;
    }
    matrix one(int n)
    {
        matrix ans={0};memset(ans.a,0,sizeof(ans.a));
        ans.n=ans.m=n;
        f(i,1,n) ans.a[i][i]=1;
        return ans;
    }
    matrix power(matrix x,int k)
    {
        matrix ans=one(x.n);
        while(k)
        {
            if(k&1) ans=ans*x;
            x=x*x;k>>=1;
        }
        return ans;
    }
};
using namespace matrixs;
int T,n;
signed main()
{
    matrixs_mod=1e9+7;
	matrix a;
    a.a[1][1]=a.a[1][2]=a.a[1][3]=1;
    a.n=1;a.m=3;
    cin>>T;
    while(T--)
    {
        matrix c;
        c.a[1][1]=0,c.a[1][2]=0,c.a[1][3]=1;
        c.a[2][1]=1,c.a[2][2]=0,c.a[2][3]=0;
        c.a[3][1]=0,c.a[3][2]=1,c.a[3][3]=1;
        c.n=c.m=3;
        n=read();
        if(n<=3) printf("%lld\n",a.a[1][n]);
        else printf("%lld\n",(a*power(c,n-3)).a[1][3]);
    }
	return 0;
}