#include <iostream>
using ll=long long;
using namespace std;
ll x=1;
int main() {
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) x*=i;
	if(x%(n+1)==0) puts("YES");
	else puts("NO");
	return 0;
}