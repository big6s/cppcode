#include <iostream>
#include <set>
using namespace std;
const int inf = 200010;
int n;
set<int> st[2]; // 下标
int main() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		st[x].insert(i);
	}
	st[0].insert(inf), st[1].insert(inf);
	bool p = (*st[1].begin()) < (*st[0].begin()); // 选更大的一堆
	while (st[p].size() > 1) {
		// 找不完了就从头开始
		int nw = *(st[p].upper_bound(nw));
		if (nw == inf) {
			nw = 0;
			p = (*st[1].begin()) < (*st[0].begin()); // p要重新选
			putchar('\n');
			continue;
		}
		printf("%d ", nw);
		st[p].erase(nw);
		p ^= 1; // 取另外一堆
	}
	putchar('\n');
	while (st[1].size() > 1) printf("%d\n", *st[1].begin()), st[1].erase(*st[1].begin());
	while (st[0].size() > 1) printf("%d\n", *st[0].begin()), st[0].erase(*st[0].begin());
	return 0;
}