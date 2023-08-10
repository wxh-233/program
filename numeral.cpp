#include<bits/stdc++.h>
#define min(x,y) x<y?x:y
#define int long long
using namespace std;
const int mod=998244353;
int n;
int op,x,y;
struct que{
    int cnt,num;
};
struct fuccf{
    que s[2000005]={0};
    int head=0,taxl=0;
    void push(que t)
    {
        s[++taxl]=t;return;
        if(taxl>900000)taxl=1;
    }
}q;
int a[5000005][11];
int b[5000005];
int ans,len;
void init()
{
    for(int i=1;i<=5000000;i++)
        for(int j=1;j<=9;j++)
            a[i][j]=(a[i-1][j]*10%mod+j)%mod;
    b[0]=1;
    for(int i=1;i<=5000000;i++)
        b[i]=(b[i-1]*10)%mod;
}
int fpow(int a,int b,int k)
{
	int ans=1%k;
	int base=a%k;
	while(b)
	{
	    if(b&1)
	    {   
                ans=(ans*base)%k;
	    }
	    base=(base*base)%k;
	    b>>=1;
		
	}
	return ans;
} 
signed main()
{
    freopen("numeral.in","r",stdin);
    freopen("numeral.out","w",stdout);
    init();
    cin>>n;
    ans=1;
    q.push(que{1,1});len++;
    while(n--)
    {
        scanf("%lld",&op);
        if(op==1)
        {
            scanf("%lld%lld",&x,&y);
            int k=0;
            while(x)
            {
                k=min(5000000,x);
                cout<<a[k][1]<<"\n";
                q.push(que{k,y});
                ans=(ans*b[k]+a[k][y])%mod;
                len+=k;
                x-=k;
            }
        }
        else if(op==2)
        {
            scanf("%lld",&x);
            int k=0;
            while(x)
            {
                int k=min(x,q.s[q.head].cnt);
                // cout<<a[k][1]<<endl;
                // ans-=(/*b[len-k]fpow(10,len-k,mod)**/a[k][q.s[q.head].num])%mod;
                ans=(ans+mod)%mod;
                q.s[q.head].cnt-=k;
                len-=k;
                if(!q.s[q.head].cnt)
                    q.head++;
                if(q.head>900000)
                    q.head=0;
                x-=k;
            }
        }
        else if(op==3)
            printf("%lld\n",ans);
    }
    return 0;
}