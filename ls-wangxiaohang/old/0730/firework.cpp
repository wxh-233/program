#include<bits/stdc++.h>
using namespace std;
namespace wxh666{
    #define getchar getchar_unlocked
    #define putchar putchar_unlocked
    #define f(a,b,c) for(int a=b;a<=c;a++)
    inline string read()
    {
        string in;
        cin>>in;
        return " "+in;
    }
    #define in read()
};using namespace wxh666;
string T;
int n;
int c;
string s;
struct Trie{
    int to[6],cnt;
}e[1000005];int ecnt=1;
void adds(int k,int c,string s,int t)
{
    if(t==s.size()) return;
    if(!e[k].to[s[t]-'a'])
    {
        e[k].to[s[t]-'a']=++ecnt;
        e[e[k].to[s[t]-'a']].cnt=0x3f3f3f3f;
    }
    e[e[k].to[s[t]-'a']].cnt=min(c,e[e[k].to[s[t]-'a']].cnt);
    adds(e[k].to[s[t]-'a'],c,s,t+1);
}
void add(int c,string s)
{
    f(i,1,s.size()-1) adds(1,c,s,i);
}
int ans=0x7f7f7f7f,ansc;
void dfs(int k,int t,int cnt)
{
    if(t>=T.size())
    {
        if(ans>cnt) ans=cnt,ansc=1;
        else if(ans==cnt) ansc++;
        return;
    }
    if(cnt+e[k].cnt>ans) return;
    if(e[k].to[T[t]-'a'])
    {
        if(t>=T.size()-1) dfs(e[k].to[T[t]-'a'],t+1,cnt+e[e[k].to[T[t]-'a']].cnt);
        else dfs(e[k].to[T[t]-'a'],t+1,cnt);
    }
    if(k!=1)
        dfs(1,t,cnt+e[k].cnt);
}
int main()
{
    freopen("firework.in","r",stdin);
    freopen("firework.out","w",stdout);
    T=read();
    cin>>n;
    f(i,1,n) scanf("%d",&c),s=read(),add(c,s);
    dfs(1,1,0);
    cout<<ans<<" "<<ansc;
    return 0;
}