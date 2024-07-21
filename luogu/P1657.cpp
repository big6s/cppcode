#include <iostream>
using namespace std;
const int N = 23;
int a[N][2], t, vis[N], x;
void dfs(int dp) {
	if (dp > x) {
		t++;
		return;
	}
	for (int i = 1; i <= x; i++) {
		if (vis[i]) continue;
		if (a[dp][0] == i || a[dp][1]==i) {
			vis[i] = 1;
			dfs(dp + 1);
			vis[i] = 0;
		}
	}
}

int  main() {
	cin >> x;
	for (int i = 1; i <= x; i++) {
		cin >> a[i][0] >> a[i][1];
	}
	dfs(1);
	cout << t;
	return 0;
}