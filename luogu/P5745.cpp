#include <iostream>
using namespace std;
const int N=4e6+3;
int a[N],sum,l,r,mx=-1e9;
int main() {
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	int i=1,j=1;
	while(i<=n) {
		while(j<=n && sum+a[j]<=m) sum+=a[j++];
		if(sum<=m&&sum>mx) {
			mx=sum;
			l=i,r=j-1;
		}
		sum-=a[i++];
	}
	cout<<l<<' '<<r<<' '<<mx;
	return 0;
}