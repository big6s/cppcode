#include <iostream>
using ll = long long;
using namespace std;
bool check(ll n) {
	if(n==1) return 1;
	ll s=0;
	for(int i=1;i*i<=n;i++) {
		if(n%i) continue;
		int j=n/i;
		if(i*i==n || j==n) {
			s+=i;
		} else {
			s+=i+j;
		}
	}
	if(s+1==n) return 1;
	return 0;
}
const int mod=998244353;
ll qpow(ll x) {
	ll d=2, ans=1;
	while(x) {
		if(x&1) ans=(ans*d)%mod;
		d=(d*d)%mod;
		x>>=1;
	}
	return ans;
}
int main() {
	ll k;
	cin>>k;
	cout<<qpow(k-1)%mod;
//	ll num=1;
//	for(ll i=1;i<=k;i++) {
//		while(!check(num)) num++;
//		cout<<num<<' ';
//		num++;
//	}
	return 0;
}