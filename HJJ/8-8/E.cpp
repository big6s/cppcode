#include <bits/stdc++.h>
using namespace std;
const int N=110;
//f1[i]��ʾ�������ң�������Ҹ�˳���ҳ�λ��i����м����ӵ͵��ߵ���
//f2[i]��ʾ�������󣬰�����ҵ�˳���ҳ�λ��i�ұ��м����Ӹߵ��͵���
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