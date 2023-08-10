#include<bits/stdc++.h>
#define f(i,j,k) for(int i=j;i<=k;i++)
using namespace std;
struct d{
    double num[11];
}q[12],ans,deta;
int n;
double dis[12];
double oula(d x,d y)
{
    double out=0;
    f(i,1,n) out+=(x.num[i]-y.num[i])*(x.num[i]-y.num[i]);
    return sqrt(out);
}
int main()
{
	cin>>n;
    f(i,1,n+1) f(j,1,n) scanf("%lf",&q[i].num[j]),ans.num[j]+=q[i].num[j]/(n+1);
    for(double T=10000;T>=0.0001;T*=0.9999988)
    {
        // printf("%0.3lf %0.3lf\n",ans.num[1],ans.num[2]);
        double mid=0;
        f(i,1,n+1) dis[i]=oula(ans,q[i]),mid+=dis[i];
        mid/=n+1;
        f(i,1,n) deta.num[i]=0;
        f(i,1,n+1) f(j,1,n)
            if(q[i].num[j]!=ans.num[j])
            deta.num[j]+=(dis[i]-mid)*(q[i].num[j]-ans.num[j])/mid;
        f(i,1,n) ans.num[i]+=deta.num[i]*T;
    }
    f(i,1,n)
        printf("%0.3lf ",ans.num[i]);
	return 0;
}