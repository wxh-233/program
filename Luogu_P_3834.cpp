#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5+10;
int read(){
    int a=0,b=1;
    char ch=getchar();
    for(;ch<'0'||ch>'9';ch=getchar()) b=1;
    for(;ch>='0'&&ch<='9';ch=getchar()) a=(a*10)+(ch-48);
    return a*b;
}
int n,m;
int cnt;
int tot;
int mum[N],num[N],rot[N];
int tri[N<<5],lef[N<<5],rit[N<<5];
int build(int l,int r){
    int re=++cnt;
    tri[re]=0;
    int mid=(l+r)/2;
    if(l==r) return re;
    lef[re]=build(l,mid);rit[re]=build(mid+1,r);
    return re;
}
int update(int pre,int l,int r,int x){
    int re=++cnt;
    tri[re]=tri[pre]+1;
    int mid=(l+r)/2;
    if(l==r) return re;

    if(x<=mid) rit[re]=rit[pre],lef[re]=update(lef[pre],l,mid,x);
    else lef[re]=lef[pre],rit[re]=update(rit[pre],mid+1,r,x);
    return re;
}
int ask(int las,int nxt,int l,int r,int k){
    if(l==r) return l;
    int ls=tri[lef[nxt]]-tri[lef[las]];
    int mid=(l+r)/2;
    if(ls>=k) return ask(lef[las],lef[nxt],l,mid,k);
    else return ask(rit[las],rit[nxt],mid+1,r,k-ls);
}
signed main(){
    n=read(),m=read();
    for(int i=1;i<=n;i++) num[i]=mum[i]=read();
    sort(num+1,num+1+n);
    tot=unique(num+1,num+1+n)-num-1;
    rot[0]=build(1,tot);
    for(int i=1;i<=n;i++){
        int to=lower_bound(num+1,num+1+tot,mum[i])-num;
        rot[i]=update(rot[i-1],1,tot,to);
    }
    while(m--){
        int u,v,w;
        u=read(),v=read(),w=read();
        int to=ask(rot[u-1],rot[v],1,tot,w);
        printf("%lld\n",num[to]);
    }
    return 0;
}
/*

*/