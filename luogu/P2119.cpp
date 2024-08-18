#include <iostream>
#include <algorithm>
using namespace std;
const int N=50010;
int n,m;
int a[N],b[N],c[N],d[N];
int x[N],vis[N];
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++) {
		cin>>x[i];
		vis[x[i]]++;
	}
	for(int t=1;t*9<n;t++){
		int sum=0;
		for(int D=9*t+2;D<=n;D++){
			int A=D-9*t-1;
			int B=A+2*t;
			int C=D-t;
			sum+=vis[A]*vis[B];
			c[C]+=vis[D]*sum;
			d[D]+=vis[C]*sum;
		}
		sum=0;
		for(int A=n-9*t-1;A;A--){
			int B=A+2*t;
			int C=B+6*t+1;
			int D=A+9*t+1;
			sum+=vis[C]*vis[D];
			a[A]+=vis[B]*sum;
			b[B]+=vis[A]*sum;
		}
	}
	for(int i=1;i<=m;i++) {
		printf("%d %d %d %d\n",a[x[i]],b[x[i]],c[x[i]],d[x[i]]);
	}
	return 0;
}
