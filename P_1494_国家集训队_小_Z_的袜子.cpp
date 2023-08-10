#include<bits/stdc++.h>
#define int long long
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
int color[50005];
struct que{
    int l,r,id;
}t[50005];
struct last{
    int l,r;
}ans[50005];
int ct[50005];
int x,y;
int mor,mol,mori;
signed main()
{
	cin>>n>>m;
    len=sqrt(n);
    f(i,1,n) color[i]=in;
    f(i,1,m) t[i].l=in,t[i].r=in,t[i].id=i;
    sort(1+t,1+t+m,[&](auto x,auto y){
        return ((x.l/len)==(y.l/len))?(((x.l/len)&1)?(x.r<y.r):(x.r>y.r)):(x.l<y.l);
    });
    mor=mol=1;
    ct[color[1]]=1;
    f(i,1,m)
    {
        int l=t[i].l,r=t[i].r;
        if(l==r) {ans[t[i].id].l=0,ans[t[i].id].r=1;continue;}
        while(mol>l) --mol,mori-=ct[color[mol]]*(ct[color[mol]]-1),ct[color[mol]]++,mori+=ct[color[mol]]*(ct[color[mol]]-1);
        while(mor<r) ++mor,mori-=ct[color[mor]]*(ct[color[mor]]-1),ct[color[mor]]++,mori+=ct[color[mor]]*(ct[color[mor]]-1);
        while(mol<l) mori-=ct[color[mol]]*(ct[color[mol]]-1),ct[color[mol]]--,mori+=ct[color[mol]]*(ct[color[mol]]-1),mol++;
        while(mor>r) mori-=ct[color[mor]]*(ct[color[mor]]-1),ct[color[mor]]--,mori+=ct[color[mor]]*(ct[color[mor]]-1),mor--;
        ans[t[i].id].l=mori,ans[t[i].id].r=(r-l+1)*(r-l);
    }
    f(i,1,m)
    {
        int gcd=__gcd(ans[i].l,ans[i].r);
        printf("%d/%d\n",ans[i].l/gcd,ans[i].r/gcd);
    }
	return 0;
}