#include <iostream>
using namespace std;
using ll = long long;
const int N = 2e3 + 5;
const int mod = 998244353;
//ans[n][m]=sum[0][0]+sum[0][1]+...+sum[0][m]+sum[1][0]+...+sum[n][m]
ll c[N][N],sum[N][N],ans[N][N]; //sum[n][m]=c(n,0)+...+c(n,m)
void init() {				//预处理出所有可能询问的数据
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i)
				c[i][j] = 1;
			else			//利用组合数恒等式递推计算
				c[i][j] = (1ll*c[i - 1][j] + c[i - 1][j - 1]) % mod;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	init();
	int t;
	cin>>t;
	for(int i=0;i<N-3;i++) {
		sum[i][0]=c[i][0]%mod;
		for(int j=1;j<N-3;j++) {
			sum[i][j]=(1ll*sum[i][j-1]+c[i][j])%mod;
		}
	}
	ans[0][0]=1;
	for(int j=1;j<N-3;j++) {
		ans[0][j]=(1ll*ans[0][j-1]+sum[0][j])%mod;
	}
	for(int i=0;i<N-3;i++) {
		ans[i][0]=(1ll*ans[i-1][0]+sum[i][0])%mod;
	}
	for(int i=1;i<N-3;i++) {
		for(int j=1;j<N-3;j++) {
			ans[i][j]=((1ll*ans[i-1][j]+ans[i][j-1]-ans[i-1][j-1]+mod)%mod+1ll*sum[i][j])%mod;
		}
	}
	while(t--) {
		int n,m;
		cin>>n>>m;
		cout<<ans[n][m]<<'\n';
	}
	return 0;
}