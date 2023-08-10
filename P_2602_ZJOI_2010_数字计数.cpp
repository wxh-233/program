#include<bits/stdc++.h>
#define int long long
using namespace std;
int a,b;
int ten[20],f[20];
int cnta[20],cntb[20];
void search(int x,int *cnt)
{
	int num[20]={0},l=0;
	while(x) {num[++l]=x%10;x/=10;}
	for(int i=l;i>=1;i--)
	{
		for(int j=0;j<=9;j++)
			cnt[j]+=f[i-1]*num[i];
		for(int j=0;j<num[i];j++)
			cnt[j]+=ten[i-1];
		int cnts=0;
		for(int j=i-1;j>=1;j--)
			cnts=cnts*10+num[j];
		cnt[num[i]]+=cnts+1;
		cnt[0]-=ten[i-1];
	}
}
signed main()
{
	cin>>a>>b;
	ten[0]=1;
	for(int i=1;i<=13;i++)
	{
		f[i]=f[i-1]*10+ten[i-1];
		ten[i]=10*ten[i-1];
	}
	search(a-1,cnta);
	search(b,cntb);
	for(int i=0;i<=9;i++)
		printf("%lld ",cntb[i]-cnta[i]);
	return 0;
}