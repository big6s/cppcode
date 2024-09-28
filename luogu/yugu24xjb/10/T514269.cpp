#include <iostream>
#include <cstring>
using namespace std;
const int N=1e4+3;
int cur,cnt[N],num[N];
int main() {
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		cur=0;
		memset(cnt,0,sizeof cnt),
		memset(num,-1,sizeof num);
		for(int i=2;i*i<=n;i++) {
			if(n%i) continue;
			int tmp_cnt=0;
			num[++cur]=i;
			while(n%i==0) {
				tmp_cnt++;
				n/=i;
			}
			cnt[cur]=tmp_cnt;
		}
		if(n>1) num[++cur]=n, cnt[cur]=1;
		int tmp[10], tc=0;
		memset(tmp,-1,sizeof tmp);
		for(int i=1;i<=cur && tc<=5;i++)
			for(int j=1;j<=cnt[i] && tc<=5;j++) tmp[++tc]=num[i];
		cout<<tmp[2]<<' '<<num[2]<<'\n';
	}
	return 0;
}
