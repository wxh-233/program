#include<bits/stdc++.h>
using namespace std;
namespace wxh666{
    #define getchar getchar_unlocked
    #define putchar putchar_unlocked
    #define sqrt(a) __builtin_sqrt(a)
    #define f(a,b,c) for(int a=b;a<=c;a++)
    string read()
    {
        string in;
        cin>>in;
        return " "+in;
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
int T,n;
string s;
int main()
{
    freopen("guess.in","r",stdin);
    freopen("guess.out","w",stdout);
    cin>>T;
    while(T--)
    {
        cin>>n;s=in;
        int cnt1=0,cnt0=0;
        f(i,1,s.size()-1) s[i]=='1'?cnt1++:cnt0++;
        int cnt=min(cnt1,cnt0);
        if(!cnt) {printf("jerry\n");continue;}
        if(/*(s.size()-2)*/(cnt1+cnt0)&1) printf("tom\n");
        else printf("jerry\n");
    }
    return 0;
}