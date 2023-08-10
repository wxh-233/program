#include<bits/stdc++.h>
using namespace std;
int nxt[1000005],k;
string s,s1=" ",s2=" ";
int main()
{
	cin>>s;
	s1+=s;
	cin>>s;
	s2+=s;
	for(int i=2;i<s2.size();i++)
	{
		while(k&&s2[i]!=s2[k+1]) k=nxt[k];
		if(s2[i]==s2[k+1]) k++,nxt[i]=nxt[i-1]+1;
	}
	for(int i=1;i<s2.size();i++)
		printf("%d ",nxt[i]);
	return 0;
}