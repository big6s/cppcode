#include <iostream>
using namespace std;
const int N=1e6+3;
//f[i][0]: 上到第i层没能量了的最小搬运的高度，f[i][1]:上到第i层后已经储能完毕的最小搬运的高度
int h[N],f[N][2];
int main() {
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>h[i];
	f[1][1]=h[1]; f[1][0]=0;
	for(int i=2;i<=n;i++) {
		f[i][0]=min(f[i-2][1],f[i-1][1]);
		f[i][1]=min(f[i-1][1],f[i-1][0])+h[i];
	}
	cout<<min(f[n][0],f[n][1]);
	return 0;
}