#include <iostream>
using namespace std;
const int mod=1e9+7;
int n, sum1, sum2, sum3;
int main() {
	cin>>n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin>>x;
		x %= mod;
		sum3 = (sum3 + 1ll * sum2 * x % mod) % mod;
		sum2 = (sum2 + 1ll * sum1 * x % mod) % mod;
		sum1 = (sum1 + x) % mod;
	}
	cout<<sum3*6ll%mod;
	return 0;
}