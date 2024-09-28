#include <iostream>
using namespace std;
const int mod=998244353;
int qpow(int x,int y) {
	int ans=1;
	while(y) {
		if(y&1) ans=(1ll*ans*x)%mod;
		x=(1ll*x*x)%mod;
		y>>=1;
	}
	return ans;
}
int main() {
	int n;
	cin>>n;
	cout<<(qpow(25,n-1)*26ll)%mod;
	return 0;
}
