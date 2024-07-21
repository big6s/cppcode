#include <iostream>
#include <algorithm>
using namespace std;
int w, x, h, ans, q;
int a[105][105][105];

int main() {
	cin >> w >> x >> h >> q;
	while (q--) {
		int x1, y1, z1, x2, y2, z2;
		cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
		if (x1 > x2) swap(x1, x2);
		if (y1 > y2) swap(y1, y2);
		if (z1 > z2) swap(z1, z2);
		for (int i = x1; i < x2; i++) {
			for (int j = y1; j < y2; j++) {
				for (int k = z1; k < z2; k++)
					a[i][j][k] = 1;
			}
		}
	}
	for (int i = 0; i < w; i++) {
		for (int j = 0; j < x; j++) {
			for (int k = 0; k < h; k++) {
				ans+=!a[i][j][k];
			}
		}
	}
	cout << ans << endl;
	return 0;
}
