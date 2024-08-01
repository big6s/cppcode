#include <iostream>
#include <cstring>
using ll = long long;
using namespace std;
const int N = 1e6 + 3;
const int pt[4] = {2,3,7,11};
int a[N],cnt[15];
bool check(int n,int* cnt) {
	for (int i = 1; i <= n; ++i) {
		if (a[i] % 154 == 0 || a[i] % 147 == 0) return 1;
		if (a[i] % 21 == 0 && cnt[7]>=2) return 1;
		if (a[i] % 49 == 0 && cnt[3]) return 1;
		if (a[i] % 77 == 0 && cnt[2]) return 1;
		if (a[i] % 14 == 0 && cnt[11]) return 1;
		if (a[i] % 22 == 0 && cnt[7]) return 1;
	}
	return 0;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		string s;
		int n;
		ll k;
		cin >> n >> s;
		for (int i = 1; i <= n; i++) cin >> a[i];
		if (s.size() < 17) {
			k = stoll(s);
		} else {
			k = ll(1e16);
		}
		ll sum=0;
		for(int i=1;i<=n;i++) sum+=a[i];
		if(sum>=k) {
			puts("Yes");
			continue;
		}
		int cnt[15]={0};
		for (int i = 1; i <= n; ++i) {
			for (auto j:pt) {
				if (a[i] % j == 0) cnt[j]++;
			}
		}
		if (n == 1) {
			if (a[1] >= k) puts("Yes");
			else puts("No");
			continue;
		}
		if (check(n,cnt)) puts("Yes");
		else puts("No");
	}
	return 0;
}