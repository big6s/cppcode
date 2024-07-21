#include <bits/stdc++.h>
#define N int(1e5 + 10)
using namespace std;
map<pair<int, int>, int> p;
int main() {
	int n, q;
	scanf("%d%d", &n, &q);
	while (q--) {
		int op, i, j;
		scanf("%d%d%d", &op, &i, &j);
		if (op == 1) {
			int k;
			scanf("%d", &k);
			p[{i, j}] = k;
		} else {
			printf("%d\n", p[{i, j}]);
		}
	}
	return 0;
}