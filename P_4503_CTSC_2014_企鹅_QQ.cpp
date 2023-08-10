#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
int n,l,S;
ull has[2][205],sh;
ull bz[205];
string s;
string read()
{
	string in;
	cin>>in;
	return " "+in;
}

map<ull,int>q;
int ans;
int main()
{
	cin>>n>>l>>S;
	bz[0]=1;
	for(int i=1;i<=l+1;i++)
		bz[i]=bz[i-1]*131;
	while(n--)
	{
		s=read();
		for(int i=1;i<=l;i++)
			has[0][i]=has[0][i-1]*131+s[i];//,cout<<has[0][i]<<" ";
		// cout<<endl;
		for(int i=l;i>=1;i--)
			has[1][i]=has[1][i+1]*131+s[i];//,cout<<has[1][i]<<" ";
		// cout<<endl;
		for(int i=1;i<=l;i++)
		{
			sh=has[0][i-1]*bz[l-i]+has[1][i+1];
			// cout<<sh<<" "<<has[0][i-1]<<" "<<bz[l-i]<<" "<<has[1][i+1]<<endl;
			if(q[sh]) ans+=q[sh];//,cout<<sh<<" 666\n";
			q[sh]++;
		}
		// cout<<ans<<endl;
	}
	cout<<ans<<endl;
	return 0;
}