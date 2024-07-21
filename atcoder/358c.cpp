#include <iostream>
using namespace std;
int vis[15],final,n,m,mi=1e9;
void dfs(int dp,int now,int num) {
	if(dp>n) {
		if(num==final) {
			mi=min(mi,now);
		}
		return ;
	}
	dfs(dp+1,now+1,num|vis[dp]);
	dfs(dp+1,now,num);
}
int main() {
	cin>>n>>m;
	final=(1<<m)-1;
	for(int i=1;i<=n;i++) {
		string s;
		cin>>s;
		int x=0;
		for(int j=0;j<m;j++) if(s[j]=='o') x|=(1<<(m-j-1));
		vis[i]=x;
	}
	dfs(1,0,0);
	cout<<mi;
	return 0;
}