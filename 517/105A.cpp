#include <iostream>
using namespace std;
int a[30], sum[30];
bool vis[3000];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) { vis[sum[j] - sum[i - 1]] = 1; }
	}
	for (int i = 1; i <= sum[n]; i++) {
		if (!vis[i]) return 0 & puts("No");
	}
	puts("Yes");
	return 0;
}