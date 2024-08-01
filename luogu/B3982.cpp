#include <iostream>
#include <map>
using namespace std;
int n, m, c, cnt;
string s, t, cmp[20], tt;
map<string, int> title;
struct node {
	bool op; // int/str
	int x;
	string y;
};
vector<node> a[120];
bool isstr(string s) {
	int cnt = 0;
	for (char c : s) cnt+=isdigit(c);
	return cnt < s.size();
}
bool ccmp(vector<node> a, vector<node> b) {
	for (int i = 1; i <= c; i++) {
		int op = cmp[i].back();
		string t = cmp[i].substr(0, cmp[i].size() - 1);
		int j = title[t];
		if (op == '+') {
			if (!a[j].op) {
				if (a[j].x == b[j].x)
					continue;
				return a[j].x < b[j].x;
			} else {
				if (a[j].y == b[j].y)
					continue;
				return a[j].y < b[j].y;
			}
		} else {
			if (!a[j].op) {
				if (a[j].x == b[j].x)
					continue;
				return a[j].x > b[j].x;
			} else {
				if (a[j].y == b[j].y)
					continue;
				return a[j].y > b[j].y;
			}
		}
	}
	return a[0].x < b[0].x;
}

int main() {
	cin >> n >> s;
	tt = s;
	s += ',';
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ',') {
			title[t] = ++m;
			t = "";
			continue;
		}
		t += s[i];
	}
	for (int i = 1; i < n; i++) {
		a[i].resize(m + 20);
		cin >> s;
		s += ',';
		t = "";
		a[i][0].x = i;
		int cnt = 0;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == ',') {
				cnt++;
				a[i][cnt].op = isstr(t);
				if (!a[i][cnt].op)
					a[i][cnt].x = stoi(t);
				else
					a[i][cnt].y = t;
				t = "";
				continue;
			}
			t += s[j];
		}
	}
	cin >> c;
	for (int i = 1; i <= c; i++)
		cin >> cmp[i];
	sort(a + 1, a + n, ccmp);
	cout << tt << '\n';
	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= m; j++) {
			if (!a[i][j].op) cout << a[i][j].x;
			else cout << a[i][j].y;
			if(j<m) cout<<',';
		}
		cout<<'\0';
	}
	return 0;
}