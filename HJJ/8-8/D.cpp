#include <bits/stdc++.h>
using namespace std;
const int N=2e5+3;
// f[i] ��ʾǰi��Ԫ�ص�����Ӷκ�
int a[N], f[N];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int ans = -1e9;
	for (int i = 1; i <= n; i++) {
		f[i] = max(a[i], f[i - 1] + a[i]);
		ans = max(ans, f[i]);
	}
	cout << ans;
	return 0;
}