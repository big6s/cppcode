#include <iostream>
#include <map>
using ll = long long;
using namespace std;
const int N=2e5+3;
map<ll, ll> m;
ll a[N],c,ans;
int main() {
	int n;
	cin >> n >> c;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		m[a[i]]++;
	}
	for (int i = 1; i <= n; i++) ans += m[a[i]-c];
	cout << ans << '\n';
	return 0;
}