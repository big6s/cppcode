#include <iostream>
using ll= long long;
using namespace std;
const int N = 200010;
int a[N], b[N];
ll x[N], y[N];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		b[i] = a[i] - a[i - 1];
	}
	for (int i = 2, j = n; i <= n; i++, j--) {
		if(b[i]<=0) x[i]=x[i-1]-b[i]+1;
		else x[i]=x[i-1];
		if(b[j]>=0) y[j]=y[j+1]+b[j]+1;
		else y[j]=y[j+1];
	}
	ll ans = 1e18;
	for (int i = 1; i <= n; i++)
		ans = min(ans, max(x[i], y[i + 1]));
	cout << ans;
	return 0;
}