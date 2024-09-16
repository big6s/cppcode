#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
using pii = pair<int, int>;
const int N=5e5+3;
struct Edge {
	int v,nxt,cost;
}edge[N<<1];
int cnt,head[N];
void add(int u,int v,int c=0) {
	edge[++cnt]={v,head[u],c};
	head[u]=cnt;
}
int dis[N];
bool vis[N];
void dijkstra(int s) {
	memset(dis,0x3f,sizeof(dis));
	dis[s]=0;
	priority_queue<pii,vector<pii>,greater<pii> > pts;
	pts.push(make_pair(0,s));
	while(!pts.empty()) {
		int u=pts.top().second;
		pts.pop();
		if(!vis[u]) {
			vis[u]=1;
			for(int i=head[u];i;i=edge[i].nxt) {
				int v=edge[i].v;
				if(dis[v]>dis[u]+edge[i].cost)  {
					dis[v]=dis[u]+edge[i].cost;
					pts.push(make_pair(dis[v],v));
				}
			}
		}
	}
}

int main() {
	int n,m,k,s,t;
	cin>>n>>m>>k>>s>>t;
	for(int i=0;i<m;++i) {
		int u,v,c;
		cin>>u>>v>>c;
		add(u,v,c);
		add(v,u,c);
		for(int j=1;j<=k;++j) {
			add(u+(j-1)*n,v+j*n);
			add(v+(j-1)*n,u+j*n);
			add(u+j*n,v+j*n,c);
			add(v+j*n,u+j*n,c);
		}
	}
	for(int i=1;i<=k;++i)
		add(t+(i-1)*n,t+i*n);
	dijkstra(s);
	cout<<dis[t+k*n];
	return 0;
}
