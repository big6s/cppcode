#include <iostream>
#include <cstring>
using namespace std;
const int N=250003;
int n, m, a, b, x1[N], y1[N], x2[N], y2[N], mx[N];
int abs(int x) {
	if(x<0) return -x;
	return x;
}
int main() {
	cin>>n>>m>>a>>b;
	for (int i = 1; i <= a; i++) cin>>x1[i]>>y1[i];
	for (int i = 1; i <= b; i++) cin>>x2[i]>>y2[i];
	memset(mx, 127, sizeof(mx));
	for (int i = 1; i <= b; i++)
		for (int j = 1; j <= a; j++)
			mx[i] = min(mx[i], abs(x1[j] - x2[i]) + abs(y1[j] - y2[i]));
	for (int i = 1; i <= b; i++) cout<<mx[i]<<'\n';
	return 0;
}
