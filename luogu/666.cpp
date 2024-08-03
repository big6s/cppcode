#include <iostream>
#include <set>
using namespace std;
int f[13]={0,0,1,1};
int main() {
	for(int i=4;i<=10;i++) f[i]=f[i-2]+f[i-3];
	cout<<f[10];
	return 0;
}
