#include <iostream>
#include <stack>
using ll = long long;
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin>>t;
	while(t--) {
		stack<ll> stk;
		int n;
		cin>>n;
		for(int i=1;i<=n;i++) {
			string s;
			cin>>s;
			if(s=="add") {
				ll x;
				cin>>x;
				stk.push(x);
			}
			else if(s=="remove") {
				if(stk.empty()) cout<<"Empty\n";
				else stk.pop();
			}
			else if(s=="peek") {
				if(stk.empty()) cout<<"NoBook!\n";
				else cout<<stk.top()<<'\n';
			}
			else {
				cout<<stk.size()<<'\n';
			}
		}
	}
	return 0;
}