#include <iostream>
#include <algorithm>
using namespace std;

const int N=2e5+3;
struct node {
	int x,y;
	friend bool operator<(node a, node b) {
		return a.x < b.x;
	}
}a[N];
int n, b[N], len;

int main () {
	cin>>n;
	for (int i = 1; i <= n; i++) {
		cin>>a[i].x>>a[i].y;
	}
	sort(a + 1, a + 1 + n);
	b[++len] = a[1].y;
	for (int i = 2; i <= n; i++) {
		int it = upper_bound(b + 1, b + len + 1, a[i].y) - b;
		b[it] = a[i].y;
		if (it > len) {
			len++;
		}
	}
	cout<<len;
	return 0;
}