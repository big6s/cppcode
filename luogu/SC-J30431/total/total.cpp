#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int N = 510;
int ar[N],br[N];
bool calc(int a,int b,int x,int y,int k) {
	return abs(a-x)+abs(b-y)>=k;
}
int main() {
	freopen("total.in","r",stdin);
	freopen("total.out","w",stdout);
	int n,m,k,ans=0;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++) {
		scanf("%d%d",&ar[i],&br[i]);
	}
	for(int x=1;x<=n;x++) {
		for(int y=1;y<=n;y++) {
			bool f=1;
			for(int i=1;i<=m;i++) {
				int a=ar[i],b=br[i];
				f&=calc(a,b,x,y,k);
				if(!f) break;
			}
			ans+=f;
		}
	}
//	for(int i=1;i<=m;i++) {
//		int a=ar[i], b=br[i];
//		for(int x=1;x<=a && x<=n;x++) {
//	//		1<=y<=b && y<=n && y<=a+b-k-x
//			fprintf(stderr,"x=%d: %d\n",x,min({max(a-x+b-k,0),n,b}));
//			ans+=min({max(a-x+b-k,0),n,b});
//	//		max(k+x+b-a,b+1)<=y<=n
//			fprintf(stderr,"x=%d: %d\n",x,n-max(k+x+b-a,b+1)+1);
//			ans+=n-max(k+x+b-a,b+1)+1;
//		}
//		for(int x=a+1;x<=n;x++) {
//	//		1<=y<=b && y<=(x+b-a-k) && y<=n
//			fprintf(stderr,"x=%d: %d\n",x,min({b,x+b-a-k,n}));
//			ans+=min({b,x+b-a-k,n});
//	//		(b+1)<=y<=n && k+b+a-x<=y
//			fprintf(stderr,"x=%d: %d\n",x,n-max(b+1,k+b+a-x)+1);
//			ans+=n-max(b+1,k+b+a-x)+1;
//		}
//	}
	printf("%d",ans);
	return 0;
}
