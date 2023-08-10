#include<bits/stdc++.h>
using namespace std;
int n;
unsigned long long has[10005];
string s;
string read()
{
	string in;
	cin>>in;
	return " "+in;
}
int search(char x)
{
	if(x>='0'&&x<='9') return x-'0';
	if(x>='a'&&x<='z') return x-'a'+10;
	if(x>='A'&&x<='Z') return x-'A'+10+26;
	return 100;
}
void hashs(string s,int i,unsigned long long *hash)
{
	for(int _=1;_<s.size();_++)
		hash[i]=hash[i]*131+search(s[_]);
}
map<unsigned long long,bool>q;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		s=read();
		hashs(s,i,has);
		q[has[i]]=true;
	}
	cout<<q.size();
	return 0;
}