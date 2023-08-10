#include<bits/stdc++.h>
using namespace std;
struct jz{
    int num[105][105];
    int n,m;
    void in()
    {
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                int l=scanf("%d",&num[i][j]);
    }
}t,z;
jz operator *(jz x,jz y)
{
    jz ans={0};
    ans.n=x.n;
    ans.m=y.m;
    // cout<<x.n<<" "<<y.m<<endl;
    for(int i=1;i<=x.n;i++)
        for(int k=1;k<=y.m;k++)
            for(int j=1;j<=x.m;j++)
                ans.num[i][k]+=x.num[i][j]*y.num[j][k];
    return ans;
}
int n,m,p;
int main()
{
    int l=scanf("%d%d",&n,&m);
    t.n=n;
    t.m=m;
    t.in();
    int i=scanf("%d",&p);
    z.n=m;
    z.m=p;
    z.in();
    jz ans={0};
    ans=t*z;
    // cout<<(t*z).num[1][1];
    // return 0;
    // cout<<ans.n<<" "<<ans.m<<endl;
    // return 0;
    for(int i=1;i<=ans.n;i++)
    {
        for(int j=1;j<=ans.m;j++)
            printf("%d ",ans.num[i][j]);
        cout<<endl;
    }
	return 0;
}