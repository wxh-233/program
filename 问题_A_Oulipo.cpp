#include<bits/stdc++.h>
#define int unsigned long long
#define guo continue
#define tiao break
#define g return 0
using namespace std;
typedef int haxi;
char s1[1000005],s2[1000005];
haxi ha[1000005],has,mod[1000005];
int t;
signed main()
{
	mod[1]=1;
	mod[2]=31;
	for(int i=3;i<=1000000;i++)
		mod[i]=mod[i-1]*mod[2];
	cin>>t;
	while(t--)
	{
		memset(ha,0,sizeof(ha));
		ha[0]=0;has=0;
		int ans=0;
		cin>>s1 + 1>>s2 + 1;
		int l1=strlen(s1+1),l2=strlen(s2+1);
		for(int i=1;i<=l1;i++)
			has=has*mod[2]+(s1[i]-'A'+1);
		for(int i=1;i<=l2;i++)
			ha[i]=mod[2]*ha[i-1]+(s2[i]-'A'+1);
//	  cout<<has<<endl<<endl;
//	  for(int i=0;i<=l2-l1;i++)
//		  cout<<ha[i+l1]-(ha[i]*mod[l1+1])<<endl;
//	  cout<<endl<<endl;
		for(int i=0;i<=l2-l1;i++)
			if(has==ha[i+l1]-(ha[i]*mod[l1+1]))
				ans++;
		cout<<ans<<endl;
	}
	g;
}
/*
 
1
AZA
AZAZAZA
 
给出两个串S1和S2（只有大写字母），求S1在S2中出现了多少次。
例如S1=“ABA”，S2=“ABABA”，答案为2。
输入T组数据，对每组数据输出结果。每组数据保证strlen(S1)≤104，strlen(S2)≤106。
*/