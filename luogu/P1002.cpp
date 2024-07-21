#include <iostream>
#define ll long long
using namespace std;
int main() {
	int bx, by, mx, my;
	cin>>bx>>by>>mx>>my;
	bx+=2,by+=2,mx+=2,my+=2;
	f[2] = 1;
	for (int i = 2; i <= bx; i++) {
		for (int j = 2; j <= by; j++) {
			if (check(i, j)) {
				f[j] = 0;
				continue;
			}
			f[j] += f[j - 1];
		}
	}
	cout<<f[by];
	return 0;
}