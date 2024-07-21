#include <iostream>
using namespace std;

int x;
char s[2005][2005];
int pw3(int x) {
	int y=1;
	while(x--) y*=3;
	return y;
}
void fun(int x, int y, int k) {
	if (k == 0) {
		s[x][y] = 1;
		return ;
	}
	int t = k / 3;
	fun(x, y, t);
	fun(x + t, y, t);
	fun(x + t * 2, y, t);
	fun(x, y + t, t);
	fun(x, y + t * 2, t);
	fun(x + t, y + t * 2, t);
	fun(x + t * 2, y + t, t);
	fun(x + t * 2, y + t * 2, t);
}
int main() {
	cin >> x;
	if (!x) {
		cout << "#";
		return 0;
	}
	int t = pw3(x);
	fun(1, 1, t);
	for (int i = 1; i <= t; i++) {
		for (int j = 1; j <= t; j++) {
			if(s[i][j]) putchar('#');
			else putchar('.');
		}
		putchar('\n');
	}
	return 0;
}