#include <iostream>
using namespace std;
int n,m,a[510][510],b[510][510],f[510][510];
int main() {
	while(cin >> n >> m && n && m) {
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=m; j++) {
				cin >> a[i][j];
				a[i][j]+=a[i][j-1];
			}
		}
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=m; j++) {
				cin >> b[i][j];
				b[i][j] += b[i-1][j];
			}
		}
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=m; j++) {
				f[i][j] = max(f[i-1][j]+a[i][j],f[i][j-1]+b[i][j]);
			}
		}
		cout<<f[n][m]<<'\n';
	}
	return 0;
}