#include<bits/stdc++.h>
using namespace std;
string s;

string read()
{
    string in;
    cin>>in;
    return " "+in;
}
int n;
int cnt;
int main()
{
    cin>>n;
	s=read();
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='T') cnt++;
        if(cnt>=(n+1>>1)) {cout<<"T\n";return 0;}
        if(i-cnt>=(n+1>>1)) {cout<<"A\n";return 0;}
    }
	return 0;
}