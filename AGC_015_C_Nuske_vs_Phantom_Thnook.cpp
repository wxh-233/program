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
int n,m,t;
int dt[2005][2005],sum[2005][2005];
int l[2005][2005],r[2005][2005];
int a,b,c,d;
int ans;
int main()
{
	cin>>n>>m>>t;
    f(i,1,n)
    {
        f(j,1,m)
        {
            scanf("%1d",&dt[i][j]);
            sum[i][j]=dt[i][j]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
            if(dt[i][j])
            {
                if(dt[i-1][j]) l[i][j]++;
                if(dt[i][j-1]) r[i][j]++;
            }
            l[i][j]+=l[i-1][j]+l[i][j-1]-l[i-1][j-1];
            r[i][j]+=r[i-1][j]+r[i][j-1]-r[i-1][j-1];
        }
    }
    f(i,1,t)
    {
        scanf("%d%d%d%d",&a,&b,&c,&d);
        ans=sum[c][d]-sum[c][b-1]-sum[a-1][d]+sum[a-1][b-1];
        ans-=l[c][d]+l[a][b-1]-l[c][b-1]-l[a][d];
        ans-=r[c][d]+r[a-1][b]-r[c][b]-r[a-1][d];
        printf("%d\n",ans);
    }
	return 0;
}
