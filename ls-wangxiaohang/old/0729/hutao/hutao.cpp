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
const int mod=998244353;
int ans=1;
int n,k;
int cnt;
inline void qy()
{
    f(i,1,ans) if(!(ans%i)) cnt++;
}
signed main()
{
    // freopen("hutao.in","r",stdin);
    // freopen("hutao.out","w",stdout);
    cin>>n>>k;
    if(n>=mod&&(n-k+1)<=mod)
    {
        cout<<"0";
        return 0;
    }
    f(i,n-k+1,n) ans=(ans*(i%mod)/((i-(n-k))%mod))%mod;
    qy();
    cout<<cnt<<endl;
    return 0;
}