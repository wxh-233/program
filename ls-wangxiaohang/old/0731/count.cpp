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
int n,m,Q;
int a,b,c,d;
string s;
int dt[1005][1005],vis[1005][1005];
int dx[5]={0,1,0,0,-1};
int dy[5]={0,0,1,-1,0};
void dfs(int x,int y)
{
    vis[x][y]=1;
    f(i,1,4)
    {
        int xx=x+dx[i],yy=y+dy[i];
        if(xx<a||yy<b||xx>c||xx>d) continue;
        if(!dt[xx][yy]) continue;
        if(vis[xx][yy]) continue;
        dfs(xx,yy);
    }
}
int main()
{
    cin>>n>>m>>Q;
    f(i,1,n)
    {
        // s=in;
        cin>>s;
        f(j,1,m) dt[i][j]=s[j-1]-'0';
    }
    while(Q--)
    {
        scanf("%d%d%d%d",&a,&b,&c,&d);
        int cnt=0;
        f(i,a,c) f(j,b,d) {if(dt[i][j]&&(!vis[i][j])) ++cnt,dfs(i,j);vis[i][j]=0;}
        printf("%d\n",cnt);
    }
    return 0;
}