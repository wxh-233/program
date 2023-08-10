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
        for(int j=1;j<=n;j++)\
            printf("%d ",dt[i][j]);\
        cout<<endl;\
    }
};using namespace wxh666;
int n,m,v,e;
int c[2005],d[2005];
double k[2005];
int dt[305][305];
double dp[2005][2005][2];
int x,y,z;
double ans;
signed main()
{
    memset(dt,0x3f,sizeof(dt));
    cin>>n>>m>>v>>e;
    f(i,1,n) c[i]=in;
    f(i,1,n) d[i]=in;
    f(i,1,n) scanf("%lf",&k[i]);
	f(i,1,e) x=in,y=in,z=in,dt[x][y]=dt[y][x]=min(dt[x][y],z);
    f(k,1,v) f(i,1,v) f(j,1,v) dt[i][j]=min(dt[i][j],dt[i][k]+dt[k][j]);
    f(i,1,v) dt[i][i]=dt[i][0]=dt[0][i]=0;
    f(i,0,n) f(j,0,m) dp[i][j][0]=dp[i][j][1]=1e17+5; 
    dp[1][0][0]=dp[1][1][1]=0;
    f(i,2,n)
    {
        dp[i][0][0]=dp[i-1][0][0]+dt[c[i-1]][c[i]];
        f(j,1,min(i,m))
        {
            dp[i][j][0]=min(dp[i][j][0],min(dp[i-1][j][0]+dt[c[i-1]][c[i]],dp[i-1][j][1]+dt[c[i-1]][c[i]]*(1-k[i-1])+dt[d[i-1]][c[i]]*k[i-1]));
            dp[i][j][1]=min(dp[i][j][1],min(dp[i-1][j-1][0]+dt[c[i-1]][c[i]]*(1-k[i])+dt[c[i-1]][d[i]]*k[i],dp[i-1][j-1][1]+dt[d[i-1]][d[i]]*k[i]*k[i-1]+dt[d[i-1]][c[i]]*k[i-1]*(1-k[i])+dt[c[i-1]][d[i]]*(1-k[i-1])*k[i]+dt[c[i-1]][c[i]]*(1-k[i-1])*(1-k[i])));
        }
    }
    ans=1e17+5;
    f(i,0,m) ans=min(ans,min(dp[n][i][0],dp[n][i][1]));
    printf("%.2lf",ans);
	return 0;
}