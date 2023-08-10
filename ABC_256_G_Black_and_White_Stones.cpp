#include<bits/stdc++.h>
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
namespace matrixs{
    int matrixs_mod=2147483647;
    struct matrix{
        int a[5][5]={0};
        int n=0,m=0;
        // void in(int x=-1,int y=-1)
        // {
        //     if(x==-1) scanf("%lld",&x);
        //     if(y==-1) scanf("%lld",&y);
        //     n=x,m=y;
        //     f(i,1,n) f(j,1,m) scanf("%lld",&a[i][j]);
        // }
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
int c[10005][10005];
int n,d;
void init()
{
    c[1][1]=1;
    f(i,1,1e4) c[i][i]=c[i][0]=1;
    f(i,2,1e4)
        f(j,1,1e4)
            c[i][j]=c[i][j-1]+c[i-1][j-1];
}


// dp[i][0]=dp[i-1][0]*C(d-2,j-2)+dp[i-1][1]*C(d-2,j-1)
// dp[i][1]=dp[i-1][0]*C(d-2,j-1)+dp[i-1][1]*C(d-2,j)


int ans=0;
int main()
{
    matrixs_mod=998244353;
    init();
    matrix a;
    a.n=2;a.m=1;
    a.a[1][1]=a.a[1][0]=1;
	cin>>n>>d;
    f(j,1,d)
    {
        matrix x;
        x.a[1][1]=c[d-2][j-1];x.a[1][2]=c[d-2][j-2];
        x.a[2][1]=c[d-2][j];x.a[2][2]=c[d-2][j-1];
        x.n=x.m=2;
        ans=(ans+(power(x,n-1)*a).a[1][1]%matrixs_mod+
        (power(x,n-1)*a).a[2][1]%matrixs_mod)%matrixs_mod;
    }
    cout<<ans<<endl;
	return 0;
}