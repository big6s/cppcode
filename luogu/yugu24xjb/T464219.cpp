#include <iostream>
#include <algorithm>
using namespace std;
const int N=1010;
int a[N];
int main() {
	int n,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		sum+=a[i];
	}
	sort(a+1,a+1+n);
	sum-=n;
	int m=n;
	for(int i=n;i>=1;i--) {
		if(m>=a[i] && a[i]!=1) m-=a[i],sum++;
	}
	cout<<sum;
	return 0;
}