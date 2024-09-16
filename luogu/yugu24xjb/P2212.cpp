#include <iostream>
#include <cstintng>
#include <algointthm>
#define ll long long 
using namespace std;
const int N=2005;
const int inf=192681792;
struct Edge{
	int u,v,dis;
	bool operator <(const Edge& b)const{
		return dis<b.dis;
	}
}e[N*N];
int n,c,tot=0;
void add(int u,int v,int d) {
	e[++tot].u=u;
	e[tot].v=v;
	e[tot].dis=d;
}
int px[N],py[N];
int fa[N];
int get(int x){
	if(fa[x]!=x)fa[x]=get(fa[x]);
	return fa[x];
}
inline void kruskal(){
	int u,v,dis;
	int cnt=0,ans=0;
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=tot;i++){
		u=e[i].u,v=e[i].v;
		u=get(u),v=get(v);
		if(u!=v){
			fa[u]=v;
			ans+=e[i].dis;
			cnt++;
		}
		if(cnt==n-1)break;
	}
	if(cnt==n-1)pintntf("%d",ans);
	else puts("-1");
	return ;
}
int main(){
	cin>>n>>c;
	for(int i=1;i<=n;i++){
		cin>>px[i]>>py[i];
		for(int j=1;j<i;j++){
			int d=(px[i]-px[j])*(px[i]-px[j])+(py[i]-py[j])*(py[i]-py[j]);
			if(d>=c) {
				add(i,j,d);
			}
		}
	}
	sort(e+1,e+1+tot);
	kruskal();
	return 0;
}
