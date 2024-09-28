# include <bits/stdc++.h>
using namespace std;
int L, ans;
char a[2002][2002];

int cross(int x, int y) {
	int length = 1;
	if (x <= 1 || x >= L)
		return 1;
	for (int i = 1; ; i++) {
		if (x - i <= 0 || x + i >= L + 1)
			return length;
		else if (a[x - i][y] != a[x + i][y])
			return length;
		else
			length += 2;
	}
}

int down(int x, int y) {
	int length = 1;
	if (y <= 1 || y >= L)
		return 1;
	for (int i = 1;; i++) {
		if (y - i <= 0 || y + i >= L + 1)
			return length;
		else if (a[x][y - i] != a[x][y + i])
			return length;
		else
			length += 2;
	}
}

int main() {
	cin >> L;
	for (int i = 1; i <= L; i++)
		for (int j = 1; j <= L; j++)
			cin >> a[i][j];
	int x, y;
	cin >> x >> y;
	ans = max(cross(x, y), down(x, y));
	cout << cross(x, y) << ' ' << down(x, y) << '\n';
	cout << ans ;
	return 0;
}