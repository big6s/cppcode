#include <iostream>
using namespace std;
string ans,a,b;
void dfs(int l1, int r1, int l2, int r2) {
	if (l1 > r1 || l2 > r2) return ;
	int rt = -1;
	for (int i = l2; i <= r2; i++) {
		if (a[l1] == b[i]) {
			rt = i;
			break;
		}
	}
	int len=rt-l2;
	dfs(l1 + 1, l1 + len, l2, l2 + len - 1);
	dfs(l1 + len + 1, r1, rt + 1, r2);
	ans+=a[l1];
}
int main() {
	cin>>b>>a;
	int len = a.size();
	dfs(0,len-1,0,len-1);
	cout<<ans;
	return 0;
}