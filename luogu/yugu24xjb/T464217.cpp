#include <iostream>
#define int long long
using namespace std;
const int N=1e5+3;
int a[N];
signed main() {
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cout<<0-a[i]<<' ';
	return 0;
}