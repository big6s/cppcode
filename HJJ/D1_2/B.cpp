#include <iostream>
using namespace std;

int main() {
	int n,t,ans=0;
	cin>>n>>t;
	for(int i=0;i<=n;i++) {
		for(int j=0;j<=n;j++) {
			if(i+j>n) break;
			for(int k=0;k<=n;k++) {
				if(i+j+k>n) break;
				if(i*j*k<=t) ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}