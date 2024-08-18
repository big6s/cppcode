#include <iostream>
#include <algorithm>
using ll = long long;
using namespace std;
const int N=2e5+3;
int a[N],b[N];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	ll ans=0;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	for(int i=1;i<=n;i++) {
		int l=a[i]-b[i], r=a[i]+b[i], cnt=0;
		int *pl=lower_bound(a+1,a+i,l), *pr=upper_bound(a+1,a+i,r)-1;
		int tl=pl-a, tr=pr-a;
		// for(int j=1;j<i;j++) {
		// 	if(a[j]>=l && a[j]<=r) cnt++;
		// }
		if(!tr || !tl) continue;
		cnt=tr-tl+1;
		ans+=cnt;
	}
	cout<<ans;
	return 0;
}