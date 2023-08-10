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
	#define in read()
};using namespace wxh666;
void amazing(int a,int b,int c,int d,int &x,int &y)
{
    if(a<b&&c>d) x=y=1;
    else amazing(d%c,c,b-(d/c)*a,a,y,x),y+=(d/c)*x;
}
int a,b,c,d;
int x,y;
signed main()
{
	while(cin>>a>>b>>c>>d)
    {
        amazing(a,b,c,d,x,y);
        printf("%lld/%lld\n",x,y);
    }
	return 0;
}