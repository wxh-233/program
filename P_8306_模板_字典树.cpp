#include<bits/stdc++.h>
using namespace std;
struct trie{
	int to[66];
	int end=0;
	int size=0;
}t[3000005];
int cnt=1;
int T,n,q;
string in,s=" ";
inline int search(int x)
{
	if(s[x]>='0'&&s[x]<='9') return s[x]-'0'+1;
	if(s[x]>='A'&&s[x]<='Z') return s[x]-'A'+1+10;
	if(s[x]>='a'&&s[x]<='z') return s[x]-'a'+1+10+26;
}
void add(int k,int x,int kq)
{
	if(x==s.size())
	{
		t[k].end++;
		t[k].size++;
		t[kq].size++;
		return;
	}
	if(!t[k].to[search(x)]) t[k].to[search(x)]=++cnt;
	t[kq].size-=t[k].size;
	add(t[k].to[search(x)],x+1,k);
	t[kq].size+=t[k].size;
}
int ask(int k,int x)
{
	if(x==s.size()) return t[k].size;
	if(!t[k].to[search(x)]) return 0;
	return ask(t[k].to[search(x)],x+1);
}
int main()
{
	cin>>T;
	while(T--)
	{
		for(int i=1;i<=cnt;i++)
		{
			t[i].end=t[i].size=0;
			for(int j=1;j<=62;j++)
				t[i].to[j]=0;
		}
		cnt=1;
		scanf("%d%d",&n,&q);
		while(n--)
		{
			s=" ";
			cin>>in;
			s+=in;
			add(1,1,1);
		}
		while(q--)
		{
			s=" ";
			cin>>in;
			s+=in;
			printf("%d\n",ask(1,1));
		}
	}
	return 0;
}
