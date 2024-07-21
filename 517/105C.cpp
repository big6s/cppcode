#include <iostream>
#define wa return 0&puts("A")
#define wb return 0&puts("B")
#define NO return 0&puts("NO")
using namespace std;

int main() {
	string s1, s2;
	int l1 = 0, l2 = 0;
	cin >> s1 >> s2;
	if (s1.size() == s2.size()) {
		for (int i = 0; i < s1.size(); i++) {
			if (s1[i] == 'O') l1++;
			if (s2[i] == 'O') l2++;
		}
		if (l1 == l2 || s1.size() < 3) NO;
		if (s1.size() == 3) {
			if (l1 == 3 && l2 == 0) wa;
			if (l1 == 0 && l2 == 3) wb;
			NO;
		}
		if (s1.size() == 4) {
			if (l1 > l2 && l1 - l2 > 1) wa;
			if (l2 > l1 && l2 - l1 > 1) wb;
			NO;
		}
		if (l1 > l2) wa;
		if (l2 > l1) wb;
		NO;
	}
	if (s1.size() > 5) NO;
	else {
		for (int i = 0; i < s2.size(); i++) {
			if (s1[i] == 'O') l1++;
			if (s2[i] == 'O') l2++;
		}
		if (s1.back() == 'O')	l1++;
		if (l1 > l2) {
			int x = l2 + 5 - s2.size();
			if (l1 > x) wa;
			NO;
		}
		if (l1 == l2) NO;
		int x = l1 + 5 - s1.size();
		if (l2 > x) wb;
		NO;			
	}
	return 0;
}