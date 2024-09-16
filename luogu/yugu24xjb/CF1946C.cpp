#include <iostream>
using namespace std;
const int N = 1e5+3;
int head[N], to[N], nxt[N], cnt;
void add(int u,int v) {
	to[++cnt]=v;
	nxt[cnt]=head[u];
	head[u]=cnt;
}

int main() {
	int T;
	cin>>T;
	while(T--) {
		int n,k;
		cin>>n>>k;
		for(int i=1;i<n;i++) {
			int u,v;
			cin>>u>>v;
			add(u,v), add(v,u);
		}
		int l=1,r=n-1,ans=0;
		while(l<=r) {
			int mid=(l+r)>>1;
			if(check(mid)) {
				l=mid+1;
				ans=mid;
			} else {
				r=mid-1;
			}
		}
	}
	return 0;
}
