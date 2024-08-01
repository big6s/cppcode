#include <bits/stdc++.h>
using namespace std;
const int maxn = 100001;
int n, m, num, cnt[maxn];
string s;
map<string, vector<int> >a;

int main() {
	std::ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> num;
		for (int j = 1; j <= num; j++) {
			cin >> s;
			a[s].push_back(i);
		}
	}
	cin >> m;
	for (int i = 1; i <= m; i++) {
		cin >> s;
		memset(cnt, 0, sizeof(cnt));
		for (int j = 0; j < a[s].size(); j++)
			if (cnt[a[s][j]] == 0) {
				cout << a[s][j] << " ";
				cnt[a[s][j]]++;
			}
		cout << endl;
	}
	return 0;
}