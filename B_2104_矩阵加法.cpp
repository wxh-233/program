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
    void out()
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
                printf("%d ",num[i][j]);
            putchar('\n');
        }
    }
}t,z;
jz operator *(jz x,jz y)
{
    jz ans={0};
    ans.n=x.n;
    ans.m=y.m;
    for(int i=1;i<=x.n;i++)
        for(int k=1;k<=y.m;k++)
            for(int j=1;j<=x.m;j++)
                ans.num[i][k]+=x.num[i][j]*y.num[j][k];
    return ans;
}
jz operator +(jz x,jz y)
{
    jz ans={0};
    ans.n=x.n;
    ans.m=x.m;
    for(int i=1;i<=ans.n;i++)
        for(int j=1;j<=ans.m;j++)
            ans.num[i][j]=x.num[i][j]+y.num[i][j];
    return ans;
}
int n,m;
int main()
{
	int l=scanf("%d%d",&n,&m);
    t.n=z.n=n;
    t.m=z.m=m;
    t.in();z.in();
    jz ans=t+z;
    ans.out();
	return 0;
}