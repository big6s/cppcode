#include <iostream>
using ll = unsigned long long;
using namespace std;
ll stk[1000010],top;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin>>t;
	while(t--) {
		top = 0;
		int n;
		cin>>n;
		for(int i=1;i<=n;i++) {
			string s;
			cin>>s;
			if(s=="add") {
				ll x;
				cin>>x;
				stk[++top] = x;
			}
			else if(s=="remove") {
				if(!top) cout<<"Empty\n";
				else top--;
			}
			else if(s=="peek") {
				if(!top) cout<<"NoBook!\n";
				else cout<<stk[top]<<'\n';
			}
			else {
				cout<<top<<'\n';
			}
		}
	}
	return 0;
}