#include<bits/stdc++.h>
extern "C" int Seniorious(int);
extern "C" int Chtholly(int n,int OvO)
{
    int l=1,r=n,mid=l+r>>1;
    while(l<=r)
    {
        mid=l+r>>1;
        int cnt=Seniorious(mid);
        if(cnt==0) return mid;
        if(cnt==1) r=mid-1;
        if(cnt==-1) l=mid+1;
    }
}