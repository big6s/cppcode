#include <iostream>
using namespace std;

int main() {
	int a[3];
	cin>>a[0]>>a[1]>>a[2];
	for(int i=0;i<3;i++) {
		if(a[i]==1) putchar('B');
		if(a[i]==2) putchar('Y');
		if(a[i]==3) putchar('R');
	}
	return 0;
}
