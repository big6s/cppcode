#include <iostream>
#include <cstring>
using namespace std;
const int N=2003;
char x[N], y[N];
int a[N], b[N], c[N<<1];

int main () {
	cin >> x >> y;
	int la = strlen(x), lb = strlen(y);
	for (int i = 1; i <= la; i++) a[i] = x[la - i]&15;
	for (int i = 1; i <= lb; i++) b[i] = y[lb - i]&15;
	for (int i = 1; i <= lb; i++)
		for (int j = 1; j <= la; j++) c[i + j - 1] += a[j] * b[i];
	for (int i = 1; i < la + lb; i++)
		if (c[i] > 9) {
			c[i + 1] += c[i] / 10;
			c[i] %= 10;
		}
	int len = la + lb;
	while (c[len] == 0 && len > 1) len--;
	for (int i = len; i >= 1; i--) cout << c[i];
	return 0;
}