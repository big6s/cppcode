#include <iostream>
#include <map>
using namespace std;
int t, n;
int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		int sum = 0, ans = 0;
		map<int, int> mp;
		while (n--) {
			int x;
			cin >> x;
			sum+=x;
			ans = max(ans,++mp[sum]);
		}
		cout << ans << endl;
	}
	return 0;
}