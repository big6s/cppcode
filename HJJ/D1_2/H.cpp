#include <iostream>
using namespace std;
const int N = 10;
char mp[N][N];

int main() {
	for (int i = 1; i <= 8; i++) {
		cin >> mp[i] + 1;
	}
	for (int i = 1; i <= 8; i++)
		for (int j = 1; j <= 8; j++) {
			if (mp[i][j] == '#' && mp[i - 1][j - 1] == '#') {
				if (mp[i - 1][j + 1] == '#' && mp[i + 1][j - 1] == '#' && mp[i + 1][j + 1] == '#') {
					cout << i << ' ' << j;
					return 0;
				}
			}
		}
	return 0;
}
