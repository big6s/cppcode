#include <iostream>
#include <cstring>
using namespace std;

int check(char *s) { //那种珠子
	if (*s == '0' && s[1] == '0')
		return 0;
	if (*s == '1' && s[1] == '1')
		return 2;
	return 1;
}
const int N = 2e6 + 3;
int n, m, k;
char s[N];
void funct(int &ans,int i,int &j,int *cnt) {
	ans = max(ans, i - j);
	int t = check(s+i); //对哪一类珠子进行操作
	while (j < i && !cnt[t]) {
		cnt[check(s+j)]++;
		j += 2;
	}
	if (cnt[t]) cnt[t]--;
	else j += 2;
}
int main() {
	cin >> n >> m >> k >> s;
	int len = strlen(s);
	for (int i = 0; i < len; i++)
		s[i + len] = s[i]; //复制一波
	int cnt[3] = {n, m, k}, ans = 0;
	for (int i = 0, j = 0; i < 2 * len - 2; i += 2) {
		funct(ans,i,j,cnt);
	}
	cnt[0] = n, cnt[1] = m, cnt[2] = k;
	for (int i = 1, j = 1; i < 2 * len - 1; i += 2) {
		funct(ans,i,j,cnt);
	}
	cout << min(ans, (len>>1)+(len>>1));
	return 0;
}