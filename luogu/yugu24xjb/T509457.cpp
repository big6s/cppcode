#include <iostream>
using namespace std;
int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n;
		bool fg=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) {
			int x;
			scanf("%d",&x);
			if(!x) {
				puts("yes");
				fg=1;
			}
		}
		if(!fg) puts("no");
	}
	return 0;
}
