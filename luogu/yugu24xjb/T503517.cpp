#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int N=210;
int mp[N][N];
int main() {
	int n;
	cin>>n;
	memset(mp,0x3f,sizeof mp);
	for(int i=1;i<n;i++) {
		for(int j=i+1;j<=n;j++) {
			int x;
			cin>>x;
			mp[i][j]=x;
		}
	}
	for(int k=1;k<=n;k++) {
		for(int i=1;i<=n;i++) {
			for(int j=i+1;j<=n;j++) {
				mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]);
			}
		}
	}
	cout<<mp[1][n];
	return 0;
}