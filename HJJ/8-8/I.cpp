#include <iostream>
using namespace std;
const int N=303, inf=1e9;
int f1[N][N], f2[N][N], num[N], s[N];
int main() {
	int n;
	cin>>n;
	for (int i = 1; i <= n; i++) {
		cin>>num[i];
		num[i + n] = num[i];
	}
	for(int i=1;i<=2*n;i++) s[i] = s[i - 1] + num[i];
	for (int p = 1; p < n; p++) {
		for (int i = 1; i < 2*n; i++) {
			int j=i+p;
			if(j>=2*n) break;
			f2[i][j] = inf;
			for (int k = i; k < j; k++) {
				f1[i][j] = max(f1[i][j], f1[i][k] + f1[k + 1][j] + s[j]-s[i-1]);
				f2[i][j] = min(f2[i][j], f2[i][k] + f2[k + 1][j] + s[j]-s[i-1]);
			}
		}
	}
	int mi = inf, mx = -inf;
	for (int i = 1; i <= n; i++) {
		mx = max(mx, f1[i][i + n - 1]);
		mi = min(mi, f2[i][i + n - 1]);
	}
	printf("%d\n%d", mi, mx);
	return 0;
}