#include<bits/stdc++.h>
using namespace std;
int t;
long long l,r;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
	    scanf("%lld%lld",&l,&r);
		long long cnt=(r-l+1)%9;;
		long long ans=cnt*(l%9)%9+(cnt)*(cnt-1)%9*5%9;
		printf("%lld\n",ans%9);
	}
	return 0;
}
