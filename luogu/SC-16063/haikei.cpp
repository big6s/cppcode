/*********************************************************************
    程序名: 
    版权: 
    作者: tin_ingot
    日期: 2024-08-17 18:32 
    说明: 
*********************************************************************/
#include <iostream>
#include <vector>
#define int long long
using namespace std;
const int N=1e6+3;
int mp[N];
signed main() {
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		int x;
		cin>>x;
		mp[x]+=i;
	}
	while(m--) {
		int ans=0;
		int x,y;
		cin>>x>>y;
		cout<<1ll*mp[x]*mp[y]<<'\n';
	}
	return 0;
}