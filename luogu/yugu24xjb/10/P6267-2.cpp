#include <iostream>
#include <cmath>
using ll = long long;
using namespace std;
int main() {
	ll n;
	cin>>n;
	ll x=(ll)sqrt(2*n);
	ll ans=0;
	for(ll i=1;i<=x+10;i++) {
		for(ll l=1;l<=(2*n+i-i*i)/2/i+10;l++) {
			ll sum=(l+l+i-1)*i/2;
			if(sum==n) ans++;
		}
	}
	cout<<ans;
	return 0;
}