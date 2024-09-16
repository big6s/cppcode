#include <iostream>
#include <algorithm>
using ll = long long;
using namespace std;
const int mod=1e9+7;
const int N = 1e6 + 3;
ll f[N], n, sigma, k;
ll kab(ll b) {
	ll ans=1;
	ll a=2;
	while(b>0){
		if(b&1){
			ans*=a;
			ans%=mod;
		}
		b>>=1;
		a=(a*a)%mod;
	}
	return ans;
}
int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		ll a;
		cin >> a;
		sigma += a;
		sigma %= mod;
		f[i] = max(f[i - 1] + a, a);
		if(f[i]<0) f[i]=0;
	}
	ll mx = f[1];
	for (int i = 2; i <= n; i++) mx = max(mx, f[i]);
	mx %= mod;
	cout << ((mx * (kab(k)-1)) % mod + sigma + mod) % mod;
	return 0;
}
