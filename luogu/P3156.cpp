#include <iostream>
using namespace std;
const int N=2e6+3
int a[N];
int main() {
	int n, m, q;
	cin>>n>>m;
	for (int i = 1; i <= n; i++) cin>>a[i];	
	while(m--) {
		cin>>q;
		cout<<a[q]<<'\n';
	}
	return 0;
}