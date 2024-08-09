#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 101000;
int id[N], a[N];
int main() {
	int n;
	cin>>n;
	memset(a, 63, sizeof a);
	for (int i = 1; i <= n; i++) {
		int x;
		cin>>x;
		id[x]=i;
	}
	for (int i = 1; i <= n; i++) {
		int x;
		cin>>x;
		x=id[x];
		int it = lower_bound(a + 1, a + n + 1, x) - a;
		a[it] = x;
	}
	int ans = lower_bound(a+1,a+n+1,a[0])-a-1;
	cout<<ans;
	return 0;
}