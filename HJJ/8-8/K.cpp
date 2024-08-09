#include <iostream>
#include <cstring>
using namespace std;
using ll = long long;
const int N = 53;
char s[N];
int f[N][N];
int main() {
	cin>>(s+1);
	int n = strlen(s + 1);
	for (int i = n; i > 0; i--) {
		for (int j = i; j <= n; j++) {
			if (i == j) f[i][j] = 1;
			else if (s[i] == s[j]) f[i][j] = f[i][j - 1];
			else {
				f[i][j] = n;
				for (int k = i; k < j; k++)
					f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j]);
			}
		}
	}
	cout<<f[1][n];
	return 0;
}