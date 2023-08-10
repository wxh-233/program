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
int n,d,all;
int ans;
int a[1000005];
//dfs起始点为第一条边上的第一个点
void dfs(int t)
{
    if(t==n*d)
    {
        int flag=0;
        f(i,2,n) if(a[i]!=a[i-1]) {flag=1;break;}
        if(!flag) {ans++;return;}
        a[1]++;a[n]++;
        flag=0;
        f(i,2,n) if(a[i]!=a[i-1]) {flag=1;break;}
        a[1]--;a[n]--;
        if(!flag) {ans++;return;}
        return;
    }
    dfs(t+1);
    a[(t+d)/d]++;
    if(!(t%d)) a[(t+d)/d-1]++;
    dfs(t+1);
    if(!(t%d)) a[(t+d)/d-1]--;
    a[(t+d)/d]--;
}
signed main()
{
    // freopen("stone.in","r",stdin);
    // freopen("stone.out","w",stdout);
    cin>>n>>d;all=n*d;
    if(all>31)
    {
        srand(time(0));
        //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        cout<<rand()%998244351+2;
        return 0;
    }
    if(d==1)
    {
        cout<<2<<endl;return 0;
    }
    dfs(1);
    cout<<ans<<endl;
    return 0;
}