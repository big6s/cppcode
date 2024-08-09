#include <bits/stdc++.h>
using namespace std;
const int N=110;
//f1[i]表示从左往右，按左低右高顺序找出位置i左边有几个从低到高的数
//f2[i]表示从右往左，按左高右低顺序找出位置i右边有几个从高到低的数
int a[N], f1[N], f2[N];
int main() {
	int n, ans = 1e9;
	cin>>n;
	for (int i = 1; i <= n; i++) cin>>a[i];
	for (int i = 1; i <= n; i++) {
		f1[i] = 1;
		for (int j = 1; j < i; j++)
			if (a[j] < a[i]) f1[i] = max(f1[i], f1[j]+1);
	}
	for (int i = n; i >= 1; i--) {
		f2[i]=1;
		for (int j = n; j > i; j--)
			if (a[j] < a[i]) f2[i] = max(f2[i], f2[j]+1);
	}
	for (int i = 1; i <= n; i++)
		ans = min(ans, n - f1[i] - f2[i] + 1);
	cout<<ans;
	return 0;
}