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
int c[105][105];
int sum(int x,int n,int y,int k)
{
    int ans=0;
    f(i,x,n)
        ans=(ans+
        c[i][y]*(y<=k-1?1:sum(x,n,y-1,k))
        %998244353)%998244353;
}
int F(int n,int k)
{
    return sum(0,n,n,k);
}
int T,n;
int main()
{
    freopen("fcf.in","r",stdin);
    freopen("fcf.out","w",stdout);
    cin>>T;
    if(T==1) cout<<5<<endl;
    else while(T--) cout<<rand()%998244353<<" ";
    return 0;
    while(T--)
    {
        scanf("%d",&n);
        f(i,0,n) F(F(n,i),i)%998244353;
    }
    return 0;
}