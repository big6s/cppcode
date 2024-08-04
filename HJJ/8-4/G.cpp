#include <iostream>
using namespace std;
const int N=2000005,M=1000005;
int n,m;
int df[N],s[N]; //df差分套差分，s为df的前缀和的前缀和
int main() {
	cin>>n>>m;
	int *d=df+M,*sum=s+M;
	for(int i=1;i<=n;i++) {
		int v,x;
		cin>>v>>x;
		d[x-3*v+1]++;
		d[x-2*v+1]-=2;
		d[x+1]+=2;
		d[x+2*v+1]--;
	}
	for(int i=1;i<=m;i++) {
		d[i]+=d[i-1]; //差分套差分，要算两边前缀和
		sum[i]=sum[i-1]+d[i]; //df前缀和的前缀和
	}
	for(int i=1;i<=m;i++) {
		cout<<sum[i]<<" ";
	}
	return 0;
}