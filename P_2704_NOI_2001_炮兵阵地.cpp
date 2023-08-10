#include<bits/stdc++.h>
using namespace std;
int n,m,pre[105];
vector<int>q;
long long ans=0;
long long dp[105][1<<10][1<<10];
char read()
{
	char ch=getchar();
	while(ch=='\n'||ch=='\r'||ch==' ') ch=getchar();
	return ch;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=0;j<m;j++)
			if(read()=='P')
				pre[i]|=1<<j;//初始化平原
	for(int i=(1<<(m+1))-1;i;i--)
		if(!(((i<<2)|(i<<1)|(i>>1)|(i>>2))&i))
			q.emplace_back(i);//找到可行解
	for(int i:q)//遍历解集
	{
		i&=pre[1];//与平原&得到可行解
		dp[1][i][0]=max((long long)(__builtin_popcount(i)),dp[1][i][0]);//初始化第一行答案
		ans=max(ans,dp[1][i][0]);
	}
	for(int i=2;i<=n;i++)//便利i
		for(int x:q)
		{
			x&=pre[i-2];
			for(int y:q)
			{
				y&=pre[i-1];
				if(!(x&y))
					for(int z:q)
					{
						z&=pre[i];
						if((!(x&z))&&(!(y&z)))//枚举xyz判断可行性
							dp[i][z][y]=max(dp[i][z][y],dp[i-1][y][x]+__builtin_popcount(z)),
							ans=max(ans,dp[i][z][y]);
					}
			}
		}
	cout<<ans<<endl;
	return 0;
}