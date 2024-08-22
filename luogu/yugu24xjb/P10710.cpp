#include <iostream>
#include <algorithm>
using namespace std;
int n, s, i, j, top, cnt[1005], ans = 1e9;
struct stu {
	int id, h;
	friend bool operator<(stu x, stu y) {
		return x.h < y.h;
	}
} a[1000005];
void move_r(int &r,int &sum) {
	r++;
	if (!cnt[a[r].id]) sum++;
	cnt[a[r].id]++;
}
void move_l(int &l,int r,int &sum) {
	ans = min(ans, a[r].h - a[l].h);
	cnt[a[l].id]--;
	if (!cnt[a[l].id]) sum--;
	l++;
}
int main() {
	cin >> n >> s;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= s; j++) {
			cin >> a[++top].h;
			a[top].id = i;
		}
	}
	sort(a + 1, a + 1 + top);
	int l = 1, r = 0, sum = 0;
	while (l <= top && r <= top) {	
		if (sum != n) move_r(r,sum);
		else move_l(l,r,sum);
	}
	cout << ans;
	return 0;
}