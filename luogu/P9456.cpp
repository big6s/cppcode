#include <bits/stdc++.h>
using namespace std;
const int N = 503;
int n, m, K, a[N][N][N];
int main() {
	cin >> n >> m >> K;
	for (int i = 1; i <= K; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= m; k++) 
				cin >> a[i][j][k];
		}
	}
	for (int i = K; i >= 1; i--) {
		for (int j = 1; j <= n; j++) {
			bool b = 0;
			for (int k = 1; k <= m; k++) {
				if (a[i][j][k] == 1) {
					b = 1;
					break;
				}
			}
			cout << b << ' ';
		}
		putchar('\n');
	}
	for (int i = K; i >= 1; i--) {
		for (int j = m; j >= 1; j--) {
			bool b = 0;
			for (int k = 1; k <= n; k++) {
				if (a[i][k][j] == 1) {
					b = 1;
					break;
				}
			}
			cout << b << ' ';
		}
		putchar('\n');
	}
	for (int i = m; i >= 1; i--) {
		for (int j = 1; j <= n; j++) {
			bool b = 0;
			for (int k = 1; k <= K; k++) {
				if (a[k][j][i] == 1) {
					b = 1;
					break;
				}
			}
			cout << b << ' ';
		}
		putchar('\n');
	}
	return 0;
}