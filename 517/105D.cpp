#include<iostream>
#define N 10010
using namespace std;
int f[N<<1]={1}, way[N];
int main() {
	for(int i=1;i<=10000;i++) {
		for(int j=1;j<=(i<<1);j++) f[j]=(f[j]+f[j-1])%10000;
		way[i]=f[i<<1]%10000;
	}
	int n;
	while(cin>>n && n) {
		printf(n>7?"%04d\n":"%d\n",way[n]);
	}
	return 0;
}