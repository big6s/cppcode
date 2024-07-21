#include <iostream>
using namespace std;
double a[2010], b[2010];

int main() {
	int n, add = 0;
	cin >> n;
	for (int i = 1, t; i <= n; i++) {
		cin >> t >> a[i] >> b[i];
		if (t == 2) b[i] -= 0.1;
		if (t == 3) a[i] += 0.1;
		if (t == 4) b[i] -= 0.1, a[i] += 0.1;
		for (int j = 1; j < i; j++) {
			add += max(a[i], a[j]) <= min(b[i], b[j]);
		}
	}
	cout << add;
	return 0;
}