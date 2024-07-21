#include <bits/stdc++.h>
using namespace std;
char st[]="D:\\cpp_code\\luogu\\P2058.cpp";
int main() {
	freopen(st, "r", stdin);
	freopen("output.cpp", "w", stdout);
	string s;
	while (getline(cin, s)) {
		int size = s.size();
		for (int j = 0; j < size; j++) {
			if (s[j] == '/' && s[j + 1] == '/') {
				s.erase(s.begin() + j, s.end());
				break;
			}
		}
		cout << s << '\n';
	}
	return 0;
}
