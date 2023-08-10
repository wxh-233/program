#include<bits/stdc++.h>
using namespace std;
string s,ss;
int dt[505][505];
int h,w;
struct FUCCF{
	int x,y,now;
};
queue<FUCCF>q;
int dx[6]={0,1,-1,0,0};
int dy[6]={0,0,0,1,-1};
int vis[505][505];
int main()
{
	cin>>h>>w;
	for(int i=1;i<=h;i++)
	{
		ss=" ";
		cin>>s;
		ss+=s;
		for(int j=1;j<=w;j++)
		{
			switch (ss[j])
			{
				case 's':
					dt[i][j]=1;
					break;
				case 'n':
					dt[i][j]=2;
					break;
				case 'u':
					dt[i][j]=3;
					break;
				case 'k':
					dt[i][j]=4;
					break;
				case 'e':
					dt[i][j]=5;
					break;
			}
		}
	}
	q.push(FUCCF{1,1,1});
	if(dt[1][1]!=1)
	{
		cout<<"No"<<endl;
		return 0;
	}
	vis[1][1]=1;
	while(!q.empty())
	{
		FUCCF cht=q.front();q.pop();
		// cout<<cht.x<<" and "<<cht.y<<endl;
		if(cht.x==h&&cht.y==w)
		{
			cout<<"Yes"<<endl;
			return 0;
		}
		for(int i=1;i<=4;i++)
		{
			int xx=cht.x+dx[i],yy=cht.y+dy[i];
			// cout<<xx<<" and "<<yy<<endl;
			int nxt=cht.now+1;
			if(nxt>5) nxt-=5;
			if(xx<1||xx>h||yy<1||yy>w) continue;
			if(vis[xx][yy]) continue;
			if(nxt!=dt[xx][yy]) continue;
			vis[xx][yy]=1;
			q.push(FUCCF{xx,yy,nxt});
		}
	}
	cout<<"No"<<endl;
	return 0;
}