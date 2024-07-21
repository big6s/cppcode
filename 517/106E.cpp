#include <iostream>
using namespace std;
int main() {
	string str;
	int t;
	cin >> t;
	while (t--) {
		cin >> str;
		int st[26] = {0}, r=0, cnt=26;
		for (; r < str.size() && cnt > 0; r++) {
			if (!st[str[r] - 'a']) cnt--;
			st[str[r] - 'a']++;
		}
		if (r == str.size() && cnt) {
			puts("not found");
			continue;
		}
		int len = r, l, pos = 0;
		for (l = 0; r < str.size(); r++) {
			st[str[r] - 'a']++;
			while (st[str[l] - 'a'] > 1) st[str[l] - 'a']--, l++;
			if (r - l + 1 < len) pos = l, len = r - l + 1;
		}
		cout << str.substr(pos, len) << '\n';
	}
	return 0;
}