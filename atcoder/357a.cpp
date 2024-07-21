#include <iostream>
using namespace std;
const int N=110;
int a[N];
int main() {
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i],m-=a[i];
		if(m==0) {
			cout<<i;
			return 0;
		} 
		if(m<0) {
			cout<<i-1;
			return 0;
		}
	}
	if(m) cout<<n;
	return 0;
}