#include <iostream>
using namespace std;
const int N = 1e5 + 3;
int p[N], vis[N], cnt, sum;
void dfs(int x) {
	vis[x]=cnt; sum++;
	if(!vis[p[x]]) dfs(p[x]);
}
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
	}
	int mx=-1;
	for (int i=1;i<=n;i++) {
		if(vis[p[i]]) continue;
		cnt++, sum=0;
		dfs(p[i]);
		mx=max(mx,sum);
	}
	cout<<mx;
	return 0;
}
