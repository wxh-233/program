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
int n,m;
int l,r;
int st[1000005][31];
int ask(int l,int r)
{
    int k=log2(r-l+1);
    return max(st[l][k],st[r-(1<<k)+1][k]);
}
int main()
{
	cin>>n>>m;
    f(i,1,n) st[i][0]=in;
    f(j,1,21) f(i,1,n-(1<<j)+1)
        st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
    f(_,1,m)
    {
        l=in;r=in;
        printf("%d\n",ask(l,r));
    }
	return 0;
}