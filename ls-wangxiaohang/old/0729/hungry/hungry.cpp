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
int n,C;
int a[505];
struct line{
    int u,v,w;
}t[250005];int tcnt=0;
int f[505];
int getfa(int x)
{
    if(f[x]==x) return x;
    else return f[x]=getfa(f[x]);
}
int power(int x,int y)
{
    int h=1;
    while(y)
    {
        if(y&1) h=h*x%C;
        x=x*x%C;
        y>>=1;
    }
    return h%C;
}
int make(int x,int y)
{
    return ((int)(power(x,y)+power(y,x)))%C;
}
int ans,cnt;
signed main()
{
    // freopen("hungry.in","r",stdin);
    // freopen("hungry.out","w",stdout);
    cin>>n>>C;
    f(i,1,n) a[i]=in,f[i]=i;
    f(i,1,n) f(j,1,i-1) t[++tcnt].u=i,t[tcnt].v=j,t[tcnt].w=make(a[i],a[j]);
    sort(1+t,1+t+tcnt,[&](auto x,auto y){
        return x.w>y.w;
    });
    f(i,1,tcnt)
    {
        int fu=getfa(t[i].u),fv=getfa(t[i].v);
        if(fu!=fv)
        {
            ans+=t[i].w;
            cnt++;
            f[fu]=fv;
            if(cnt>=n-1) break;
        }
    }
    cout<<ans<<endl;
    return 0;
}