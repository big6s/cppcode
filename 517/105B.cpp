#include <iostream>
using namespace std;
int main() {
	int t;
	cin>>t;
	while (t--) {
		int x1, x2, y1, y2;
		cin>>x1>>y1>>x2>>y2;
		cout<<1ll*(x2-x1+1)*(y2-y1+1)<<'\n';
	}
	return 0;
}