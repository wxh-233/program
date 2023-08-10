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
            printf("%lld ",dt[i][j]);\
        cout<<endl;\
    }
};using namespace wxh666;
int n,m;
int a[100005];
int x,y;
int hz[100005];
bool dfs(int t,int cnt,int to,int y)
{
    if(cnt>to) return false;
    if(cnt+hz[t]<to) return false;
    if(cnt+hz[t]==to) return true;
    if(t>y)
    {
        if(cnt==to) return true;
        return false;
    }
    return dfs(t+1,cnt,to,y)|dfs(t+1,cnt+a[t],to,y);
}
signed main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>n;
    f(i,1,n) scanf("%lld",&a[i]);
    for(int i=n;i>=1;i--) hz[i]=hz[i+1]+a[i];
    cin>>m;
    f(i,1,m)
    {
        scanf("%lld%lld",&x,&y);
        if(x>y) swap(x,y);
        f(i,1,10000)
            if(!dfs(x,0,i,y)) {printf("%lld\n",i);break;}
    }
    return 0;
}