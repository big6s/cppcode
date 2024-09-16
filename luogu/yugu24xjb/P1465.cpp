#include <iostream>
using namespace std;
const int N = 23;
int n;
int i[N], v[N], x[N], l[N], c[N], d[N], m[N], A[N];
int ai, av, ax, al, ac, ad, am;
void mem() {
	A[1] = 1; i[1] = 1;
	A[2] = 4; i[2] = 1; v[2] = 1;
	A[3] = 5; v[3] = 1;
	A[4] = 9; i[4] = 1; x[4] = 1;
	A[5] = 10; x[5] = 1;
	A[6] = 40; x[6] = 1; l[6] = 1;
	A[7] = 50; l[7] = 1;
	A[8] = 90; x[8] = 1; c[8] = 1;
	A[9] = 100; c[9] = 1;
	A[10] = 400; c[10] = 1; d[10] = 1;
	A[11] = 500; d[11] = 1;
	A[12] = 900; c[12] = 1; m[12] = 1;
	A[13] = 1000; m[13] = 1;
}
void add(int b, int num) {
	ai += i[b] * num;
	av += v[b] * num;
	ax += x[b] * num;
	al += l[b] * num;
	ac += c[b] * num;
	ad += d[b] * num;
	am += m[b] * num;
}
int main() {
	cin>>n;
	mem();
	for (int j = 1; j <= n; j++) {
		int tp = j, now = 13;
		while (tp) {
			while (tp < A[now]) now--;
			add(now, tp / A[now]);
			tp %= A[now];
		}
	}
	if (ai) printf("I %d\n", ai);
	if (av) printf("V %d\n", av);
	if (ax) printf("X %d\n", ax);
	if (al) printf("L %d\n", al);
	if (ac) printf("C %d\n", ac);
	if (ad) printf("D %d\n", ad);
	if (am) printf("M %d\n", am);
	return 0;
}