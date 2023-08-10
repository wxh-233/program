#include<bits/stdc++.h>
#define N 11000002
using namespace std;
char s[N<<1+1];
int len,p[N<<1+1];
void manacher()
{
	int maxright=0,mid=0;
	for(int i=1;i<=len;i++)
	{
		if(i<maxright)
			p[i]=min(p[(mid<<1)-i],maxright-i+1);
		else
			p[i]=0;
		int right=i+p[i];
		for(;s[right+1]==s[i*2-(right+1)];right++);
		if(right>maxright)
			mid=i;maxright=right;
		p[i]=right-i-1;
	}
}
inline void read()
{
	char c=getchar();
	s[0]='~';s[len=1]='#';
	while(c<'a'||c>'z') c=getchar();
	while(c>='a'&&c<='z') s[++len]=c,s[++len]='#',c=getchar();
}
int ans;
int main()
{
	read();
	manacher();
	for(int i=1;i<len;i++)
		ans=max(ans,p[i]+1);
	cout<<ans<<endl;
	return 0;
}