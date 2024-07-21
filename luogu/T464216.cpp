#include <iostream>
using namespace std;

int main() {
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) putchar('Z');
	putchar('\n');
	for(int i=1;i<=n-2;i++) {
		for(int j=1;j<n-i;j++) putchar('-');
		putchar('Z');
		for(int j=n-i+1;j<=n;j++) putchar('-');
		putchar('\n');
	}
	for(int i=1;i<=n;i++) putchar('Z');
	return 0;
}