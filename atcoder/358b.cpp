#include <iostream>
using namespace std;
const int N=110;
int t[N],ans[N];
int main() {
	int n,a;
	cin>>n>>a;
	for(int i=1;i<=n;i++) {
		cin>>t[i];
	}
	ans[1]=a+t[1];
	cout<<ans[1]<<'\n';
	for(int i=2;i<=n;i++) {
		ans[i]=a+max(ans[i-1],t[i]);
		cout<<ans[i]<<'\n';
	}
	return 0;
}