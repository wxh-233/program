#include<bits/stdc++.h>
using namespace std;
#define int long long
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
int n;
signed main()
{
    cin>>n;
    matrixs_mod=1e9+7;
	matrix c;c.n=c.m=2;
    c.a[1][1]=0,c.a[1][2]=1;
    c.a[2][1]=1,c.a[2][2]=1;
    matrix ans;ans.a[1][1]=ans.a[1][2]=1;
    ans.n=1,ans.m=2;
    if(n<=2) cout<<ans.a[1][n];
    else
    {
        ans=ans*power(c,n-2);
        cout<<ans.a[1][2]<<endl;
    }
	return 0;
}