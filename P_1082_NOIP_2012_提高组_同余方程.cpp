#include<bits/stdc++.h>
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#define f(a,b,c) for(int a=b;a<=c;a++)
void exgcd(int a,int b,int &x,int &y)
{
	if(!b) {x=1;y=0;return;}
	exgcd(b,a%b,y,x);
	y-=a/b*x;
}
int ask(int a,int mod)
{
	int x,y;
	exgcd(a,mod,x,y);
	x=(x%mod+mod)%mod;
	return x;
}
using namespace std;
int a,b;
int main()
{
	cin>>a>>b;
	cout<<ask(a,b);
	return 0;
}