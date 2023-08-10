#include<bits/stdc++.h>
using namespace std;
namespace wxh666{
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
double dp[1005][1005];
int n,m,x,y;
int main()
{
	cin>>n>>m>>x>>y;
    for(int i=n-1;i>=x;i--)
        f(t,1,50)
            if(m==1) dp[i][1]=(dp[i][1]+dp[i+1][1])/2.0+1;
            else
            {
                dp[i][1]=(dp[i][1]+dp[i][2]+dp[i+1][1])/3.0+1;
                dp[i][m]=(dp[i][m]+dp[i][m-1]+dp[i+1][m])/3.0+1;
                f(j,2,m-1)
                    dp[i][j]=(dp[i][j]+dp[i][j-1]+dp[i][j+1]+dp[i+1][j])/4.0+1;
            }
    printf("%.5lf\n",dp[x][y]);
	return 0;
}