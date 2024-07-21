#include<bits/stdc++.h>
using namespace std;
const int maxn = 35;
int n, a[maxn];
int f[maxn][100];

int getp(int i, int j) {
	stack<int> st;
	long long sum = 0, lim = 1LL << j;
	while (i >= 1) {
		sum += 1LL << a[i];
		if (sum > lim) {
			break;
		}
		st.push(a[i]);
		while (st.size() >= 2) {
			int t1 = st.top();
			st.pop();
			int t2 = st.top();
			st.pop();
			if (t1 == t2) {
				st.push(t1 + 1);
			} else {
				st.push(t2);
				st.push(t1);
				break;
			}
		}
		if (sum == lim && st.size() == 1) {
			return i;
		}
		i--;
	}
	return 0;
}

int main() {
	freopen("decoration.in", "r", stdin);
	freopen("decoration.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int mx = 60;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= mx; j++) {
			int p = getp(i, j);
			f[i][j] = maxn;
			if (p) {
				for (int k = 0; k <= mx; k++) {
					if (j != k) {
						f[i][j] = min(f[p - 1][k] + i - p, f[i][j]);
					}
				}
			}
		}
		
	}
	int mi = maxn;
	for (int j = 0; j <= mx; j++) {
		mi = min(f[n][j], mi);
	}
	cout << mi << endl;
	return 0;
}