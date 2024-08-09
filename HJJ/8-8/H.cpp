#include <iostream>
#include <algorithm>
using namespace std;
int la, lb, a[110], b[110], f[110][110];
int table['Z'];
const int d[6][6] = {
	{0, 0, 0, 0, 0, 0},
	{0, 5, -1, -2, -1, -3},
	{0, -1, 5, -3, -2, -4},
	{0, -2, -3, 5, -2, -2},
	{0, -1, -2, -2, 5, -1},
	{0, -3, -4, -2, -1, 0}
};
void Input(int &len,int *arr) {
	cin >> len;
	for (int i = 1; i <= len; i++) {
		char t;
		cin >> t;
		arr[i]=table[t];
	}
}
int main() {
	table['A']=1;
	table['C']=2;
	table['G']=3;
	table['T']=4;
	Input(la,a);
	Input(lb,b);
	for (int i = 1; i <= la; i++)
		f[i][0] = f[i - 1][0] + d[a[i]][5];
	for (int i = 1; i <= lb; i++)
		f[0][i] = f[0][i - 1] + d[5][b[i]];
	for (int i = 1; i <= la; i++)
		for (int j = 1; j <= lb; j++)
			f[i][j] = max({f[i-1][j-1]+d[a[i]][b[j]], f[i-1][j]+d[a[i]][5], f[i][j-1]+d[5][b[j]]});
	cout << f[la][lb] << '\n';
	return 0;
}