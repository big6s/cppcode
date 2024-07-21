#include<iostream>
#include<algorithm>
using namespace std;
const int N=2e5+3;
int a[N],b[N];
int* lower_bound(int x) {
	int l=1,r=n;
	while(l<=r) {
		int mid=(l+r)>>1;
		if(a[mid]<x) l=mid+1;
		else r=mid-1;
	}
	return l-1;
}
int main() {
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int u=0;
	for(int i=1;i<=m;i++) {
		cin>>b[i];
		auto p=lower_bound(a+1,a+1+n,b[i]);
		if(p!=a+1+n) u+=*p,*p=0;
		else {
			cout<<-1;
			return 0;
		}
	}
	cout<<u;
	return 0;
}