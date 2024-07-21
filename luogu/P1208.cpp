#include<bits/stdc++.h>
using namespace std;
const int N=2e6+3;
class Marry{
public:
	int price,milk;
	friend bool operator<(Marry a,Marry b){
		return a.price<b.price;
	}
}a[N];
long long n,m,ans;
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>a[i].price>>a[i].milk;
	}
	sort(a+1,a+m+1);
	for(int i=1;i<=m;i++){
		if(n>a[i].milk){
			n-=a[i].milk;
			ans+=a[i].price*a[i].milk;
		}
		else {
			ans+=a[i].price*n;
			break;
		}
	}
	cout<<ans<<'\n';
	return 0;
}