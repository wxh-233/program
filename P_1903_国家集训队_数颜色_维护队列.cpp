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
int n,m,len;
int color[133335];
char op;int x,y;
int change[133335],cto[133335],ccnt;
struct que{
	int l,r,t;
}t[133335];
int main()
{
	cin>>n>>m;len=power(n,0.666);
	f(i,1,n) x=in,color[i]=x;
	f(i,1,m)
	{
		scanf("%c%d%d",&op,&x,&y);
		if(op=='Q')
		{
			t[i].l=x;
			t[i].r=y;
			t[i].t=ccnt;
		}
		else
		{
			change[++ccnt]=y;
			cto[ccnt]=x;
		}
	}
	return 0;
}