#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 210;
//f[i][j][k]表示区间[i,j]由k转化.
bool f[N][N][5], vis[5][5][5];
int q[5];
char s[N];
int change(char c) {
	if (c == 'W') return 1;
	if (c == 'I') return 2;
	if (c == 'N') return 3;
	if (c == 'G') return 4;
}
int main() {
	for (int i = 1; i <= 4; i++) scanf("%d", &q[i]);
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= q[i]; j++) {
			char c[5];
			scanf("%s", c);
			vis[i][change(c[0])][change(c[1])] = 1;
		}
	}
	scanf("%s", s + 1);
	int len = strlen(s + 1);
	for (int i = 1; i <= len; i++) f[i][i][change(s[i])] = 1;
	for (int ler = 1; ler < len; ler++)
		for (int l = 1; l <= len - ler; l++) {
			int r = l + ler;
			for (int k = l; k < r; k++)
				for (int z = 1; z <= 4; z++)
					for (int z1 = 1; z1 <= 4; z1++)
						for (int z2 = 1; z2 <= 4; z2++)
							if (vis[z][z1][z2] && f[l][k][z1] && f[k + 1][r][z2])
								f[l][r][z] = 1;
		}
	bool flg=f[1][len][1]|f[1][len][2]|f[1][len][3]|f[1][len][4];
	if (f[1][len][1]) cout << "W";
	if (f[1][len][2]) cout << "I";
	if (f[1][len][3]) cout << "N";
	if (f[1][len][4]) cout << "G";
	if (!flg) cout << "The name is wrong!";
	return 0;
}