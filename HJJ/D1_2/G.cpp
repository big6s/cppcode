#include <bits/stdc++.h>

using namespace std;

struct node {
	int dir;
	string name;
} a[100005];
int n, m, x, y;

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i].dir >> a[i].name;
	}
	int now = 0;
	for (int i = 1; i <= m; i++) {
		cin >> x >> y;
		if (a[now].dir == 0 && x == 0)
			now = (now + n - y) % n;
		else if (a[now].dir == 0 && x == 1)
			now = (now + y) % n;
		else if (a[now].dir == 1 && x == 0)
			now = (now + y) % n;
		else if (a[now].dir == 1 && x == 1)
			now = (now + n - y) % n;
	}
	cout << a[now].name << endl;
	return 0;
}