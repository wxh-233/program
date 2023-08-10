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
int n;
struct girls{
    int d;
    char lr;
    vector<int>gx;
}e[1000005];
vector<int>l;
vector<int>r;
int ans=0,cntc;
void mori_th()
{
    int cnt=cntc;
    for(double T=10;T>=0.000001;T*=0.99995)
    {
        int hl,hr,deta=0,ihl,ihr;
        hl=rand()%(n/2),ihl=l[hl];
        hr=rand()%(n/2),ihr=r[hr];
        for(auto i:e[ihl].gx)
        {
            if(i==ihr) continue;
            if(e[i].lr=='l') deta-=e[i].d;
            else deta+=e[i].d;
        }
        if(ihl!=1&&(ihl/2)!=ihr)
        {
            if(e[ihl/2].lr=='l') deta-=e[ihl].d;
            else deta+=e[ihl].d;
        }
        for(auto i:e[ihr].gx)
        {
            if(i==ihl) continue;
            if(e[i].lr=='r') deta-=e[i].d;
            else deta+=e[i].d;
        }
        if(ihr!=1&&(ihr/2)!=ihl)
        {
            if(e[ihr/2].lr=='r') deta-=e[ihr].d;
            else deta+=e[ihr].d;
        }
        swap(l[hl],r[hr]);
        swap(e[ihl].lr,e[ihr].lr);
        if(deta>0) cnt+=deta,ans=max(ans,cnt);
        else if(exp(((-deta))*T<(rand()*1.0/RAND_MAX))) cnt+=deta;
    }
    cntc=cnt;
}
signed main()
{
    // freopen("girl.in","r",stdin);
    // freopen("girl.out","w",stdout);
    cin>>n;
    if(n<3) {cout<<0<<endl;return 0;}
    f(i,1,n) scanf("%lld",&e[i].d);
    f(i,1,n/2)
    {
        if(e[i/2].lr=='l')
            ans+=e[i].d;
        l.push_back(i),e[i].lr='l';
    }
    f(i,n/2+1,n)
    {
        if(e[i/2].lr=='r')
            ans+=e[i].d;
        r.push_back(i),e[i].lr='r';
    }
    cntc=ans;
    f(i,2,n) e[i/2].gx.push_back(i);
    f(i,1,15) mori_th();
    cout<<ans<<endl;
    return 0;
}