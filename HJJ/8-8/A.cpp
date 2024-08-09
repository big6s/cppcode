#include <iostream>
using namespace std;
const int N=1100;
int f[N][N], a[N][N];
int main() {
	int r;
	cin>>r;
	for(int i=1;i<=r;i++) {
		for(int j=1;j<=i;j++) {
			cin>>a[i][j];
		}
	}
	f[1][1]=a[1][1];
	for(int i=2;i<=r;i++) {
		for(int j=1;j<=i;j++) {
			f[i][j]=max(f[i-1][j],f[i-1][j-1])+a[i][j];
		}
	}
	int ans=-1;
	for(int i=1;i<=r;i++) {
		ans=max(ans,f[r][i]);
	}
	cout<<ans;
	return 0;
}