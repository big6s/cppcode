#include <iostream>
#include <queue>
using namespace std;
int n, t, m, x;
int nation[1000005];
int ans;

struct node {
	int s, t;
};
queue<node> ship;
node h;

int main() {
	cin>>n;
	for (int i = 1; i <= n; i++) {
		cin>>t>>m;
		while (!ship.empty()) { 
			h = ship.front();
			if (h.t + 86400 <= t) { 
				nation[h.s]--;
				if (nation[h.s] == 0)
					ans--;
				ship.pop();
				continue;
			}
			break;
		}
		for (int j = 1; j <= m; ++j) { 
			cin>>x;
			h.s = x, h.t = t;
			ship.push(h);
			nation[x]++;
			if (nation[x] == 1)
				ans++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}