#include <iostream>
#include <algorithm>
using namespace std;
const int N=110;
int tm[N];
int main() {
	freopen("history.in","r",stdin);
	freopen("history.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		int h,m,s;
		scanf("%d%d%d",&h,&m,&s);
		tm[i]=h*3600+m*60+s;
	}
	sort(tm+1,tm+1+n);
	int ans=0;
	for(int i=n;i>=1;i-=2) {
		int ti=tm[i], tj=tm[i-1];
		ans+=(ti>tj)?ti:tj;
	}
	printf("%d %d %d",ans/3600,ans%3600/60,ans%60);
	return 0;
}
