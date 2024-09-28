#include <iostream>
using namespace std;
using ll = long long;
int main() {
	int n;
	ll s=0;
	cin>>n;
	for(int i=1;i<=n;i++) {
		s+=i;
		cout<<s<<'\n';
	}
	return 0;
}