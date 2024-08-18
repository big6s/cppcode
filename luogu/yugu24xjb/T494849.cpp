#include <iostream>
using namespace std;
const int N=1e5+3;
int n,a[N],b[N],mx,now;
int main() {
	cin>>n;
	for(int i=0;i<n;++i) cin>>a[i]>>b[i];
	for(int i=1;i<=5;i++) {
		int cnt=0;
		for(int j=0;j<n;++j) {
			if(a[j]==i || b[j]==i) cnt++;
			else cnt=0;
			if(cnt>mx) {
				mx=cnt;
				now=i;
			}
		}
	}
	cout<<mx<<' '<<now;
	return 0;
}
