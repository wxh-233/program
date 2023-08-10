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
int n;
int a[1005],to[1005];
// int a[1005],vis[1005];
// int to[1005],tp[1000005];
// void dfs2(int t)
// {
//     if(t>1)
//     {
//         f(i,1,n) if(a[i]!=i) goto ssb;
//         tp[t]=1;
//         return;
//     }
//     ssb:f(i,1,n) a[i]=to[a[i]];
//     dfs2(t+1);
// }
// void dfs(int t)
// {
//     if(t>n)
//     {
//         f(i,1,n) a[i]=i;
//         dfs2(1);
//         return;
//     }
//     f(i,1,n)
//     {
//         if(vis[i]) continue;
//         vis[i]=1;
//         to[t]=i;
//         dfs(t+1);
//         vis[i]=0;
//     }
// }
int ans=0;
map<int,bool>q;
// void dfss(int t)
// {
//     if(flag) cout<<t<<endl;
//     if(t>1)
//     {
//         f(i,1,n) if(a[i]!=i) goto ssb;
//         cnts[t]=1;
//         return;
//     }
//     ssb:f(i,1,n) a[i]=to[a[i]];
//     dfss(t+1);
// }
int vis[10000];
int flag=0;
int dfs666(int t,int d)
{
    // if(flag) cout<<t<<" "<<to[t]<<" "<<d<<endl;
    vis[t]=1;
    if(vis[to[t]]) return d;
    else return dfs666(to[t],d+1);
}
int gcd(int a,int b)
{
    if(!b) return a;
    return gcd(b,a%b);
}
int gcm(int a,int b)
{
    return a*b/gcd(a,b);
}
void mori_th()
{
    q[2]=1;
    f(T,1,1000)
    {
        // cout<<T<<endl;
        // if(T>=348) flag=1;
        vector<int>ch;
        ch.clear();
        int x=0,y=0;
        /*while(x==y) */x=rand()%n+1,y=rand()%n+1;
        swap(to[x],to[y]);
        f(i,1,n) a[i]=i;
        // memset(vis,0,sizeof(vis));
        f(i,1,n) {if(!vis[i]) ch.push_back(dfs666(i,1));vis[i]=0;}
        int cnt=1;
        for(auto i:ch) cnt=gcm(cnt,i);
        q[cnt+1]=true;
    }
}
int main()
{
    srand(time(0));
    cin>>n;
    f(i,1,n) a[i]=i,to[i]=i;
    f(i,1,200) mori_th();
    cout<<q.size()<<endl;
    // for(n=1;n<=1000;n++)
    // {
    //     memset(tp,0,sizeof(tp));
    //     ans=0;
    //     dfs(1);
    //     f(i,1,100000) ans+=tp[i];
    //     cout<<ans<<endl;
    // }
    return 0;
}
/*
1
2
3
4
6
6
9
11
14
16
20
23
*/