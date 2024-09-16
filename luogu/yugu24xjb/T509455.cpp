#include <iostream>
#include <algorithm>
using namespace std;
const int N=2010;
int c[N], cnt, f[N];
int find(int x) {
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
struct node {
	int u,v,w;
	friend bool operator<(node x,node y) {
		return x.w>y.w;
	}
} a[N*N];
int main() {
	int n,d=0,ans=0;
	cin>>n;
	for(int i=1; i<=n; i++) cin>>c[i];
	for(int i=1; i<=n; i++) {
		for(int j=i+1; j<=n; j++) {
			a[++cnt]= {i,j,c[i]^c[j]};
		}
	}
	sort(a+1,a+cnt+1);
	for(int i=1; i<=n; i++) f[i]=i;
	for(int i=1; i<=cnt; i++) {
		int u=find(a[i].u),v=find(a[i].v);
		if(u==v) continue;
		f[u]=v;
		ans+=a[i].w;
		d++;
		if(d==n-1) break;
	}
	cout<<ans;
	return 0;
}