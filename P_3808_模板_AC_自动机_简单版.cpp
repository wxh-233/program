#include<bits/stdc++.h>
using namespace std;
namespace wxh666{
	#define getchar getchar_unlocked
	#define putchar putchar_unlocked
	#define sqrt(a) __builtin_sqrt(a)
	#define f(a,b,c) for(int a=b;a<=c;a++)
	inline string read()
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
struct Trie{
	int to[26],fail,end;
}e[100005];int ecnt;
void add(int k,int t,string s)
{
	if(t>=s.size()) {e[k].end++;return;}
	if(!e[k].to[s[t]-'a']) e[k].to[s[t]-'a']=++ecnt;
	add(e[k].to[s[t]-'a'],t+1,s);
}
void getfail()
{
	queue<int>q;
	f(i,0,25) if(e[0].to[i]) q.push(e[0].to[i]);
	while(!q.empty())
	{
		int t=q.front();q.pop();
		f(i,0,25)
			if(e[t].to[i])
			{
				int k=t;
				while((!e[e[k].fail].to[i])&&k!=0) k=e[k].fail;

				
				if(e[e[k].fail].to[i])
					e[e[t].to[i]].fail=e[e[k].fail].to[i];
				else e[e[t].to[i]].fail=0;


				e[e[t].to[i]].end+=e[e[e[t].to[i]].fail].end;
			}
	}
}
int n;
string s;
int ans;
void search(int k,int t,string s)
{
	if(t>=s.size()) return;
	while(!e[k].to[s[t]-'a'])
	{
		k=e[k].fail;
		if(k==0){search(k,t+1,s);return;}
	}
	ans+=e[e[k].to[s[t]-'a']].end;
	for(int g=e[k].to[s[t]-'a'];g;g=e[g].fail) cerr<<g<<endl,e[g].end=0;
	search(e[k].to[s[t]-'a'],t+1,s);
}
int main()
{
	cin>>n;
	f(i,1,n) s=in,add(0,1,s);
	getfail();
	s=in;
	search(0,1,s);
	cout<<ans<<endl;
	return 0;
}