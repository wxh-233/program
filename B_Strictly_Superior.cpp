#include<bits/stdc++.h>
using namespace std;
int n,m,p[105],c[105];
int f[105][105];
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int l=scanf("%d%d",&p[i],&c[i]);
		for(int j=1;j<=c[i];j++)
			l=scanf("%d",&f[i][j]);
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			int s[105]={0},cnt=0;
			int s2[105]={0},flag=0;
			if(i==j) continue;
			if(p[i]<p[j]) continue;
			if(c[j]<c[i]) continue;
			for(int k=1;k<=c[i];k++)
				s[f[i][k]]=1;
			for(int k=1;k<=c[j];k++)
				s2[f[j][k]]=1;
			for(int k=1;k<=100;k++)
			{
				if(s[k]&&(!s2[k])) {flag=1;break;}
				if((!s[k])&&s2[k]) flag=3;
			}
			if(flag==1) continue;
			if(p[i]>p[j]||flag==3)
			{
				printf("Yes\n");
				return 0;
			}
			
		}
	printf("No");
	return 0;
}