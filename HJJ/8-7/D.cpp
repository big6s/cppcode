#include <iostream>
#include <cstring>
using namespace std;

struct pt {
	int x, y, z, tm;
}q[125100];
int a, b, c, t;
const int N=53, dx[]={1,-1,0,0,0,0}, dy[]={0,0,1,-1,0,0}, dz[]={0,0,0,0,1,-1};
int mp[N][N][N];
bool vis[N][N][N];
int bfs() {
	memset(vis,0,sizeof vis);
	memset(q,0,sizeof q);
	int ql=1,qr=0;
	q[++qr]={0,0,0,0};
	while (qr-ql+1) {
		pt f = q[ql++];
		if (f.tm >= t) return -1;
		for (int i = 0; i < 6; i++) {
			pt nxt={f.x+dx[i], f.y+dy[i], f.z+dz[i], f.tm+1};
			if (nxt.x == a - 1 && nxt.y == b - 1 && nxt.z == c - 1) return nxt.tm;
			if (nxt.x<0||nxt.x>=a||nxt.y<0||nxt.y>=b||nxt.z<0||nxt.z>=c) continue;
			if (mp[nxt.x][nxt.y][nxt.z]) continue;
			if (vis[nxt.x][nxt.y][nxt.z]) continue;
			vis[nxt.x][nxt.y][nxt.z] = 1;
			q[++qr]=nxt;
		}
	}
	return -1;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while (T--) {
		cin>>a>>b>>c>>t;
		for(int i=0;i<a;i++) {
			for(int j=0;j<b;j++) {
				for(int k=0;k<c;k++) {
					cin>>mp[i][j][k];
				}
			}
		}
		if (mp[a-1][b-1][c-1] || a + b + c - 3 > t) {
			cout<<"-1\n";
			continue;
		}
		if (a == 1 && b == 1 && c == 1) {
			cout<<"0\n";
			continue;
		}
		cout<<bfs()<<'\n';
	}
	return 0;
}