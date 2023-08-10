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
const int mod=1e9+7;
int n,q,m;
int a[100005],vis[100005];
int ans,cnts;
void dfs(int t,int all,int cnt)
{
    if(t>all)
    {
        cnt=abs(cnt);
        if(!(cnt%m)) cnts++;
        return;
    }
    f(i,1,n)
    {
        if(vis[i]) continue;
        vis[i]=1;
        dfs(t+1,all,cnt+a[i]);
        vis[i]=0;
    }
}
int jc[100005];
int fpow(int x,int k,int p=INT_MAX)
{
    int ans=1;
    while(k)
    {
        if(k&1) ans=ans*x%p;
        x=x*x%p;k>>=1;
    }
    return ans;
}
void init()
{
    jc[0]=1;
    f(i,1,n) jc[i]=(jc[i-1]*i);
}
signed main()
{
    freopen("choose.in","r",stdin);
    freopen("choose.out","w",stdout);
    cin>>n>>q;
    init();
    f(i,1,n) scanf("%lld",&a[i]);
    while(q--)
    {
        ans=0;
        scanf("%lld",&m);
        f(i,1,n)
        {
            dfs(1,i,0);
            // cerr<<jc[i]<<" "<<fpow(jc[i],mod-2,mod)<<endl;
            ans+=cnts/jc[i];//fpow(jc[i],mod-2,mod);
            // cerr<<i<<" "<<cnts<<endl;
            cnts=0;
        }
        ans++;
        printf("%lld\n",ans);
    }
    return 0;
}