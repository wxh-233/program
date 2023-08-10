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
};using namespace wxh666;
namespace matrixs{
    struct matrix{
        int a[105][105]={0};
        int n=0,m=0;
        void in(int x=-1,int y=-1)
        {
            if(x==-1) scanf("%d",&x);
            if(y==-1) scanf("%d",&y);
            n=x,m=y;
            f(i,1,n) f(j,1,m) scanf("%d",&a[i][j]);
        }
        void out()
        {
            f(i,1,n)
            {
                f(j,1,m) printf("%d ",a[i][j]);
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
        matrix ans={0};
        ans.n=x.n;ans.m=y.m;
        // cout<<x.n<<" "<<x.m<<endl;
        // cout<<y.n<<" "<<y.m<<endl;
        f(i,1,ans.n) f(j,1,ans.m) f(k,1,x.m) ans.a[i][j]+=x.a[i][k]*y.a[k][j];
        return ans;
    }
};
using namespace matrixs;
int n,m,k;
int main()
{
	cin>>n>>m>>k;
    matrix x,y;
    x.in(n,m); y.in(m,k);
    matrix z=x*y;
    z.out();
	return 0;
}