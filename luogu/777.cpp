#include<bits/stdc++.h>
using namespace std;
char s[1000005];int n,m,rk[1000005],sa[1000005],tax[1000005],tp[1000005],h[1000005];
//注意毒瘤码风：这里的h就是Height了，不是那个辅助数组H。
inline void srt()//后缀数组的桶排
{
	memset(tax,0,sizeof(tax));
	for(int i=1;i<=n;i++) tax[rk[tp[i]]]++;
	for(int i=1;i<=m;i++) tax[i]+=tax[i-1];
	for(int i=n;i>=1;i--) sa[tax[rk[tp[i]]]--]=tp[i];
}
inline void work()//求后缀数组
{
	for(int i=1;i<=n;i++) rk[i]=s[i],tp[i]=i;
	m=127,srt();
	for(int w=1,p=1,i;p<n;w<<=1,m=p)
	{
		for(p=0,i=n-w+1;i<=n;i++) tp[++p]=i;
		for(i=1;i<=n;i++) if(sa[i]>w) tp[++p]=sa[i]-w;
		srt(),memcpy(tp,rk,sizeof(rk)),rk[sa[1]]=p=1;
		for(i=2;i<=n;i++) rk[sa[i]]=(tp[sa[i]]==tp[sa[i-1]]&&tp[sa[i]+w]==tp[sa[i-1]+w]?p:++p);
	}
	for(int i=1,j=0,k;i<=n;h[rk[i]]=j,i++) for(j=(j?j-1:j),k=sa[rk[i]-1];s[i+j]==s[k+j];j++);
}
inline long long solve() {long long ans=1ll*n*(n+1)/2;for(int i=1;i<=n;i++) ans-=h[rk[i]];return ans;}
//solve就是统计答案。
//这里用了正难则反，总共有n*(n+1)/2个点，减去重复的就是答案了。
int main() {return scanf("%d%s",&n,s+1),work(),printf("%lld\n",solve()),0;}
//简洁的主程序，这次压行有点过分，主程序都压成一行了，我自裁。