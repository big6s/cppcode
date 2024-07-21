#include<bits/stdc++.h>
using namespace std;
char s[2010][75];
int nxt[2010][2010];
int f[2010];
int n;
int in[2010];
bool vis[2010];
int zan[2010];
int main()
{
freopen("code.in","r",stdin);
freopen("code.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%s",s[i]);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
		{
			if(i!=j)
			{
				if(strlen(s[i])>=strlen(s[j]))continue;
				bool flag=true;
				int len=strlen(s[i]);
				for(int k=0;k<len;++k)
					if(s[i][k]!=s[j][k])
					{
						flag=false;
						break;
					}
                //判断
				if(flag)
				{
					nxt[i][++nxt[i][0]]=j;
					++in[j];
				}
                //连边
			}
		}
	int cnt=n;
	for(int i=1;i<=n;++i)
		zan[i]=in[i];
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		{
			if(!vis[j]&&in[j]==0)
			{
				for(int k=1;k<=nxt[j][0];++k)
					--zan[nxt[j][k]];
				vis[j]=true;
				--cnt;
			}
		}
		if(cnt==0)
		{
			printf("%d",i);
			return 0;
		}
		for(int j=1;j<=n;++j)
			in[j]=zan[j];
	}
    //拓扑
	return 0;
}
