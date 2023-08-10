#include<bits/stdc++.h>
using namespace std;
namespace wxh666{
	#define getchar getchar_unlocked
	#define putchar putchar_unlocked
	#define f(a,b,c) for(register int a=b;a<=c;a++)
	inline int read()
	{
		char ch=getchar();int f=1,ans=0;
		for(;!isdigit(ch);ch=getchar()) ch=='-'?f=-1:f=1;
		for(;isdigit(ch);ch=getchar()) ans=(ans<<3)+(ans<<1)+(ch&15);
		return f*ans;
	}
	#define in read()
};using namespace wxh666;
int n,q,len;
int a[100005];
struct question{
    int l,r,xh,ans;
}e[1000005];
int mol,mor;
int vis[100005],tip;
int main()
{
	cin>>n>>q;
    len=sqrt(n);
    f(i,1,n) a[i]=in;
    f(i,1,q) e[i].l=in,e[i].r=in,e[i].xh=i;
    sort(1+e,1+e+q,[&](auto x,auto y){
        return ((x.l/len)==(y.l/len))?(x.r<y.r):(x.l<y.l);
    });
    f(i,1,q)
    {
        int l=e[i].l,r=e[i].r;
        while(mor<r) (vis[a[++mor]]++==1)?tip++:tip=tip;
        while(mor>r) (--vis[a[mor--]]==1)?tip--:tip=tip;
        while(mol<l) (--vis[a[mol++]]==1)?tip--:tip=tip;
        while(mol>l) (vis[a[--mol]]++==1)?tip++:tip=tip;
        e[i].ans=(tip?0:1);
    }
    sort(1+e,1+e+q,[&](auto x,auto y){
        return x.xh<y.xh;
    });
    f(i,1,q) if(e[i].ans) printf("Yes\n"); else printf("No\n");
	return 0;
}
