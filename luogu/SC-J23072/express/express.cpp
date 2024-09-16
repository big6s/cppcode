#include <iostream>
#include <vector>
using namespace std;
struct node {
	int x,y,z;
	node(int a=-1,int b=-1,int c=-1) {
		x=a, y=b, z=c;
	}
	bool iserr() {
		return x==-1 && y==-1 && z==-1;
	}
};
const int N=110;
int a[N][N];
int vec[N][N][N];
int n,m,k;
node find(int sz) { //可用位置
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			if(a[i][j]!=sz) continue;
			for(int l=1;l<=k;l++) {
				if(!vec[i][j][l]) {
					return {i,j,l};
				}
			}
		}
	}
	return {-1,-1,-1};
}
int main() {
#ifdef JUDGE
  freopen("express.in","r",stdin);
  freopen("express.out","w",stdout);
#endif
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			cin>>a[i][j];
		}
	}
	int t;
	cin>>t;
	while(t--) {
		int op;
		cin>>op;
		if(op==1) {
			int x;
			cin>>x;
			node f=find(x);
			if(f.iserr()) {
				puts("Reject");
				continue;
			}
			vec[f.x][f.y][f.z]=x;
			cout<<f.x<<'-'<<f.y<<'-'<<f.z<<'\n';
		}else {
			int x,y,z;
			scanf("%d-%d-%d",&x,&y,&z);
			vec[x][y][z]=0;
		}
	}
  return 0;
}
