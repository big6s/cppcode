#include <iostream>
using namespace std;

int main() {
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			bool f=0;
			if(i&1) f=1;
			else {
				if(i%4==0&&j==1) f=1;
				else if(i%4==2&&j==m) f=1;
			}
			if(f) putchar('#');
			else putchar('.');
		}
		cout<<'\n';
	}
	return 0;
}
