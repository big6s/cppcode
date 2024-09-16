#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 200010;
struct edge {
	int v, nxt; 
}e[N << 2];
int head[N], cnt;
void add(int u, int v){
	e[++cnt].v = v;
	e[cnt].nxt = head[u];
	head[u] = cnt;
}
void clear(int n){
	cnt = 0;
	for(int i = 1; i <= n; i++) head[i] = 0;
}
int k, ans;
int dfs(int u, int fa, int x){
	int lst = 1;
	for(int i = head[u]; i; i = e[i].nxt){
		int v = e[i].v;
		if(v == fa) continue;
		lst += dfs(v, u, x);
	}
	if(lst >= x) ans++, lst = 0;
	return lst;
}
bool check(int x){
	ans = 0;
	dfs(1, 0, x);
	return ans > k;
}
void solve(){
	int n;
	cin >> n >> k;
	clear(n);
	for(int i = 1; i < n; i++){
		int u, v;
		cin >> u >> v;
		add(u,v), add(v,u);
	}
	int l = 0, r = n - 1, ans = 0;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(check(mid)) l = mid + 1, ans = mid;
		else r = mid - 1;
	}
	cout << ans << '\n';
}
signed main(){
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
