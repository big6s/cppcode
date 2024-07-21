#include<iostream> 
using namespace std;
const int N=60;
int a[N][N];
int n;
void f(int k,int x,int y) {
	if(k>n*n||x>n||y>n) {
		return ;
	}
	a[x][y]=k;
	if(x==1&&y!=n) f(k+1,n,y+1);
	else if(x!=1&&y==n) f(k+1,x-1,1);
	else if(x==1&&y==n) f(k+1,x+1,y);
	else {
		if(a[x-1][y+1]) f(k+1,x+1,y);
		else f(k+1,x-1,y+1);
	}
}
int main() {
	cin>>n;
	f(1,1,(n+1)>>1);
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) cout<<a[i][j]<<' ';
		cout<<'\n';
	}
	return 0;
}