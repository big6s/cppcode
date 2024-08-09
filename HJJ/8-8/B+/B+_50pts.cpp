#include <iostream>
using namespace std;
const int N=5003;
int a[N], b[N], f[N][N];
int main() {
	int n;
	cin>>n;
	for (int i = 1; i <= n; i++) cin>>a[i];
	for (int i = 1; i <= n; i++) cin>>b[i];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[i] == b[j]) f[i][j] = f[i - 1][j - 1] + 1;
			else f[i][j] = max(f[i][j - 1], f[i - 1][j]);
		}
	}
	cout<<f[n][n];
	return 0;
}