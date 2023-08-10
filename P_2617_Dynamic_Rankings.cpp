#include<bits/stdc++.h>
using namespace std;
namespace wxh666{
	#define getchar getchar_unlocked
	#define putchar putchar_unlocked
	#define sqrt(a) __builtin_sqrt(a)
	#define f(a,b,c) for(int a=b;a<=c;a++)
	inline int read()
	{
		char ch=getchar();int f=1,ans=0;
		for(;!isdigit(ch);ch=getchar()) ch=='-'?f=-1:f=1;
		for(;isdigit(ch);ch=getchar()) ans=(ans<<3)+(ans<<1)+(ch&15);
		return f*ans;
	}
	// #define in read()
	#define cs(dt,n,m) \
    for(int i=1;i<=n;i++)\
    {\
        for(int j=1;j<=n;j++)\
            printf("%d ",dt[i][j]);\
        cout<<endl;\
    }
};using namespace wxh666;
struct x_trees{
	struct{
		int l,r,sum,lan;
	}t[2000005];
	void build(int k,int l,int r)
	{
		t[k].l=l;t[k].r=r;
		if(l==r) return;
		int mid=l+r>>1;
		build(k<<1,l,mid);
		build((k<<1)+1,mid+1,r);
	}
};
int n,m;
struct sum_x_trees:public x_trees{
	void down(int k)
	{
		t[k<<1].lan+=t[k].lan;
		t[k<<1].sum+=(t[k<<1].r-t[k<<1].l+1)*t[k].lan;
		t[(k<<1)+1].lan+=t[k].lan;
		t[(k<<1)+1].sum+=(t[(k<<1)+1].r-t[(k<<1)+1].l+1)*t[k].lan;
		t[k].lan=0;
	}
	void add(int k,int x,int y,int z)
	{
		if(t[k].l>y||t[k].r<x) return;
		if(t[k].l>=x&&t[k].r<=y)
		{
			t[k].sum+=(t[k].r-t[k].l+1)*z;
			t[k].lan+=z;
			return;
		}
		down(k);
		add(k<<1,x,y,z);
		add((k<<1)+1,x,y,z);
		t[k].sum=t[k<<1].sum+t[(k<<1)+1].sum;
	}
	int ask(int k,int x,int y)
	{
		if(t[k].l>y||t[k].r<x) return 0;
		if(t[k].l>=x&&t[k].r<=y) return t[k].sum;
		down(k);
		return ask(k<<1,x,y)+ask((k<<1)+1,x,y);
	}
}trees;
struct wxh{
	int id,l,r,k,ans,num;
	inline void prit(){printf("%d %d %d %d",id,l,r,k);}
	bool operator <(wxh x)const{return num<x.num;}
}q[50005],tr[2][50005];
int cnt[2];
void solve(int l,int r,int ql,int qr)
{
	if(l==r){f(i,ql+1,qr)if(q[i].id==2)q[i].ans=r;return;}
	int mid=(l+r+1)>>1;
	f(i,ql+1,qr)
	{
		if(q[i].id=1)
			if(q[i].k<mid) tr[0][++cnt[0]]=q[i];
			else trees.add(1,q[i].l,q[i].r),tr[1][++cnt[1]]=q[i];
		else
		{
			int t=trees.ask(1,q[i].l,q[i].r);
			if(q[i].k<=t) tr[1][++cnt[1]]=q[i];
			else q[i].k-=t,tr[0][++cnt[0]]=q[i];
		}
	}
	f(i,1,cnt[0]) q[ql+i]=tr[0][i];
	f(i,1,cnt[1])
	{
		q[ql+cnt[0]+i]=tr[1][i];
		if(tr[1][i].id==1) trees.add(tr[1][i].l,tr[1][i].r,-1;)
		int div1=ql+cnt[0],div2=ql+cnt[0]+cnt[1];
		cnt[0]=cnt[1]=0;
		if(ql!=div1) solve(l,mid-1,ql,div1);
		if(div1!=div2) solve(mid,r,div1,div2);
	}
}
int main()
{
	trees.build(1,1,n);
	cin>>n>>m;
	f(i,1,m)
	{
		scanf("%d%d%d%d",&q[i].id,&q[i].l,&q[i].r,&q[i].k);
		q[i].num=i;
	}
	solve(-n,n,0,m);sort(q+1,q+m+1);
	f(i,1,m) if(q[i].id==2) printf("%d\n",q[i].ans);
	return 0;
}