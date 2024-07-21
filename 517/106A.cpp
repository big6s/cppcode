#include <iostream>
using namespace std;

int main() {
	int a, b;
	while (cin >> a >> b) {
		int err = 0, ac = 0, mx = max(a, b);
		for (int i = 1; i <= 30; i++) {
			int num;
			cin >> num;
			if (num) {
				if (num != mx && !ac)
					err++; //Wrong_Answer
				else
					ac = 1; //Accepted
			}
		}
		if (err >= 3 || !ac) puts("N");
		else puts("Y");
	}
	return 0;
}