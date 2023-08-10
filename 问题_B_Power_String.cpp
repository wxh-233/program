#include<bits/stdc++.h>
#define guo continue
#define tiao break
#define g return 0
using namespace std;
typedef string zf;
typedef int zx;
zf s,yb,lyb;
zx flag,ans;
int main()
{
	while(cin>>s)
	{
		if(s==".") g;
		int len=s.size();
		if(len==1){printf("1\n");guo;}
		if(len==2)
			if(s[1]==s[0]){printf("2\n");guo;}
			else {printf("1\n");guo;}
		ans=0;flag=1;
		for(int i=1;i<=len;i++)
		{
			flag=1;
			if(i==len)
				if(!ans) {ans=len;tiao;}
			if(!(len%i))
			{
				yb="";
				for(int j=0;j<i;j++) yb+=s[j];
				for(int j=i;j<len;j+=i)
				{
					lyb="";
					for(int h=0;h<i;h++) lyb+=s[h+j];
					if(lyb!=yb){flag=0;tiao;}
				}
				if(flag){ans=i;tiao;}
			}
		}
		int da=len/ans;
		cout<<da<<endl;
	}
	g;
}
//求每个字符串的最短循环子串，输出循环次数。