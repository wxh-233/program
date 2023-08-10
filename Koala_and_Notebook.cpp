#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
struct wxh{
    int v,w;
};
vector<wxh>q[2000005];
int dcnt;
int n,m;
int x,y;
int dis[2000005];
int vis[2000005];
struct wxh666{
    int u,v,w;
    bool operator <(wxh666 x)const
    {
        return w>x.w;
    }
};
void BFS()
{
    queue<vector<int> >p;
    p.push({1});vis[1]=1;
    while(!p.empty())
    {
        priority_queue<wxh666>to;
        vector<int>k;
        vector<int>in;
        k=p.front();p.pop();
        for(auto i:k)
            for(auto j:q[i])
                if(!vis[j.v])
                    to.push(wxh666{i,j.v,j.w});
        int g=0;
        if(!to.empty())
            g=to.top().w;
        while(!to.empty())
        {
            wxh666 w=to.top();to.pop();
            if(vis[w.v]) continue;
            if(g!=w.w)
            {
                if(!in.empty())
                    p.push(in);
                in.clear();
                g=w.w;
            }
            vis[w.v]=1;
            dis[w.v]=(dis[w.u]*10+w.w)%mod;
            in.push_back(w.v);
        }
        if(!in.empty())
            p.push(in);
        in.clear();
    }
}
signed main()
{
	cin>>n>>m;
    dcnt=n;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&x,&y);
        stack<int>s;
        queue<int>sq;
        int _=i;
        while(_) s.push(_%10),sq.push(_%10),_/=10;
        if(s.size()==1)
        {
            q[x].push_back(wxh{y,i});
            q[y].push_back(wxh{x,i});
        }
        else
        {
            q[x].push_back(wxh{++dcnt,s.top()});
            q[dcnt].push_back(wxh{x,sq.front()});
            s.pop();sq.pop();
            while(s.size()>1)
            {
                q[dcnt].push_back(wxh{dcnt+1,s.top()});
                q[dcnt+1].push_back(wxh{dcnt,sq.front()});
                dcnt++;s.pop();sq.pop();
            }
            q[y].push_back(wxh{dcnt,sq.front()});
            q[dcnt].push_back(wxh{y,s.top()});
            ++dcnt;s.pop();sq.pop();
        }
    }
    for(int i=1;i<=dcnt;i++)
        sort(q[i].begin(),q[i].end(),[&](auto x,auto y){return x.w<y.w;});
    BFS();
    for(int i=2;i<=n;i++)
        printf("%d\n",dis[i]);
	return 0;
}