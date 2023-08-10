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
int n,k;
int a[1000005];
namespace changing{
    int flagn=1;
};using namespace changing;
namespace pts_30{
    int ans=0;
    int cl=0,flag=0;
    void dfs(int t=1)
    {
        int cnt=a[1];
        f(i,2,n) cnt=__gcd(cnt,a[i]);
        ans=max(ans,cnt);
        if((++cl)>2500000) {flag=1;return;}
        if(t>k)
            return;
        for(int i=1;i<=n;i++)
        {
            a[i]++;
            dfs(t+1);
            a[i]--;
            if(flag==1) return;
        }
    }
};
int main()
{
    freopen("gcd.in","r",stdin);
    freopen("gcd.out","w",stdout);
    cin>>n>>k;
    if(k!=n) flagn=0;
    f(i,1,n)
    {
        scanf("%d",&a[i]);
        if(a[i]!=n-1) flagn=0;
    }
    if(flagn)
    {
        cout<<n<<endl;
        return 0;
    }
    if(k<=15)
    {
        using namespace pts_30;
        dfs();
        cout<<ans<<endl;
        return 0;
    }
    return 0;
}