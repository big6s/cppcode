#include <iostream>

using namespace std;
typedef long long ll;

ll h[10101];
ll a[10101], b[10101];

int main(){
	int n;
	scanf("%lld", &n);
	for(int i = 1; i <= n; ++i) scanf("%lld", &h[i]);
	printf("0 ");
	for(int i = 2; i <= n; ++i){
		if(i % 2 == 1){
			int l = n-i+1, r = n;
			ll cz = 1e15;
			while(r >= i){
				a[r] = a[r-1] + abs(h[r] - h[l]);
				cz = min(cz, a[r]);
				--l;--r;
			}
			printf("%lld ", cz);
		}else{
			int l = n-i+1, r = n;
			ll cz = 1e15;
			while(r >= i){
				b[r] = b[r-1] + abs(h[r] - h[l]);
				cz = min(cz, b[r]);
				--l;--r;
			}
			printf("%lld ", cz);
		}
	}
	return 0;
}