#include<bits/stdc++.h>
const int N=1e5;
using namespace std;
int n,a,b,len[N],head[N],tot,dis1[N],dis2[N],sum,pos=1;
struct edge {
	int to,nxt;
} g[N];
void insert(int u,int v) {
	tot++;
	g[tot].to=v;
	g[tot].nxt=head[u];
	head[u]=tot;
}
void dfs(int x) {
	len[x]=1;
	for(int i=head[x]; i; i=g[i].nxt) {
		if(dis1[g[i].to])continue;
		dis1[g[i].to]=dis1[x]+1;
		dfs(g[i].to);
		len[x]+=len[g[i].to];
	}
}
void check(int x,int y) {
	dis2[x]=dis2[y]+n-2*len[x];
	for(int i=head[x]; i; i=g[i].nxt) {
		if(g[i].to==y)continue;
		check(g[i].to,x);
	}
}
int main() {
	cin>>n;
	for(int i=1; i<n; i++) {
		cin>>a>>b;
		insert(a,b);
		insert(b,a);
	}
	dis1[1]=1;
	dfs(1);
	for(int i=1; i<=n; i++)sum+=dis1[i];
	sum-=n;
	dis2[1]=sum;
	for(int i=head[1]; i; i=g[i].nxt)check(g[i].to,1);
	for(int i=2; i<=n; i++) {
		if(dis2[i]<sum)sum=dis2[i],pos=i;
	}
	cout<<pos<<' '<<sum;
	return 0;
}
