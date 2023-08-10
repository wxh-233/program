#include<bits/stdc++.h>
using namespace std;
constexpr int maxn=1<<10;
int n,m,ctz[maxn];
long long dp[15][105][maxn];
vector<int>q;
long long ans=0;
int main()
{
	cin>>n>>m;
	int s=(1<<n)-1;
	for(int i=0;i<=s;i++)
	{
		if(!(((i<<1)|(i>>1))&i))
			q.emplace_back(i),//放入队列
			ctz[i]=__builtin_popcount(i);//求出状态对应国王的数量
	}
	dp[0][0][0]=1;//初始化
	for(int i=1;i<=n;i++)//枚举行数
		for(int j=0;j<=m;j++)//枚举放置国王的数量
			for(int k=0;k<=min(j,n+1>>1);k++)//枚举这一行放置的国王数
				for(int x:q)//枚举这一行的状态
					if(ctz[x]==k)//判断国王数量是否符合要求
						for(int y:q)//枚举判断上一行的状态
							if(!(x&y)&&!(x<<1&y)&&!(x>>1&y))//判断状态是否合法
								dp[i][j][x]+=dp[i-1][j-k][y];//状态转移
	for(int i:q)//枚举最后一行的状态
		ans+=dp[n][m][i];//加和答案
	printf("%lld\n",ans);
	return 0;
}