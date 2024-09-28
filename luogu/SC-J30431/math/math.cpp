#include <iostream>
#include <algorithm>
using ll = long long;
using namespace std;
const int N=2e5+3;
ll lcms[N], a[N];
int lcm(int x,int y) {
	return x/__gcd(x,y)*y;
}
bool check(int p,int i) {
	for(int j=1;j<=p;j++) {
		if(a[i]%a[j]==0) {
			return 0;
		}
	}
	return 1;
}
int find(int p,int n) {
	for(int i=p+1;i<=n;i++) {
		if(check(p,i)) return a[i]; //若a[i]不是前p个数的倍数
	}
	return -1;
}
int main() {
	freopen("math.in","r",stdin);
	freopen("math.out","w",stdout);
	ll n,m;
	scanf("%d%d%lld",&n,&m,a+1);
	lcms[1]=a[1];
	for(int i=2;i<=n;i++) {
		scanf("%lld",a+i);
//		lcms[i]=lcm(lcms[i-1],a[i]);
	}
	while(m--) {
		int p;
		scanf("%d",&p);
		printf("%lld ",find(p,n));
	}
	return 0;
}