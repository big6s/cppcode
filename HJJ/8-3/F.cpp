#include<iostream>
using ll = long long;
using namespace std;
int md[203];
int main() {
	int n;
	cin>>n;
	for(int i=1,a;i<=n;i++) {
		cin>>a;
		md[((a+200)%200+200)%200]++; //md[i]是a%200出现的次数
	}
	ll ans=0;
	for(int i=0;i<200;i++) {
		ans+=1ll*md[i]*(md[i]-1)/2; //C(n,2), 因为只有两个数的组合
	}
	cout<<ans<<endl;
	return 0;
}