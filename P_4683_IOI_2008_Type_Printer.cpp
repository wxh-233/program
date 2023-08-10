#include<bits/stdc++.h>
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#define f(a,b,c) for(int a=b;a<=c;a++)
using namespace std;
struct trie{
    int to[26],end,big,siz;
}t[1000005];int tcnt=1;
string s;
string read()
{
    string in;
    cin>>in;
    return " "+in;
}
int n;
void add(int k,int p)
{
    if(p==s.size())
    {t[k].end++;t[k].siz=max(t[k].siz,1);return;}
    if(!t[k].to[s[p]-'a']) t[k].to[s[p]-'a']=++tcnt;
    add(t[k].to[s[p]-'a'],p+1);
    t[k].siz=max(t[k].siz,t[t[k].to[s[p]-'a']].siz+1);
}
queue<char>q;
int cnt;
void dfs(int k)
{
    if(t[k].end) q.push('P'),cnt++;
    int maxk=0,maxx=0,maxi=0;
    f(i,0,25)
        if((t[k].to[i])&&maxx<t[t[k].to[i]].siz)
            maxx=t[t[k].to[i]].siz,maxk=t[k].to[i],maxi=i;
    f(i,0,25)
    {
        if(t[k].to[i]==maxk) continue;
        if(!t[k].to[i]) continue;
        q.push('a'+i);
        dfs(t[k].to[i]);
    }
    if(maxk) q.push('a'+maxi),dfs(maxk);
    if(cnt==n) return;
    q.push('-');
}
int main()
{
	cin>>n;
    f(i,1,n) s=read(),add(1,1);t[0].siz=0;
    dfs(1);
    cout<<q.size()<<endl;
    while(!q.empty()) cout<<q.front()<<endl,q.pop();
	return 0;
}