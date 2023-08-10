#include<bits/stdc++.h>
#define int long long
using namespace std;
int f[100005];
int n,s;
int c[5],d[5];
signed main()
{
	for(int i=1;i<=4;i++) cin>>c[i]; cin>>n;
    f[0]=1;
    for(int i=1;i<=4;i++)
        for(int j=c[i];j<=100001;j++)
            f[j]+=f[j-c[i]];
    while(n--)
    {
	    for(int i=1;i<=4;i++)
        int l=scanf("%lld",&d[i]);int l=scanf("%lld",&s);
        int ans=0;
        for(int i=0;i<=15;i++)
        {
            int t=s;
            int cnt=0;
            for(int j=1;j<=4;j++)
                if((i>>(j-1))&1)
                    t-=c[j]*(d[j]+1),cnt^=1;
            if(t<0) continue;
            if(!cnt) ans+=f[t];
            else ans-=f[t];
        }
        printf("%lld\n",ans);
    }
	return 0;
}
