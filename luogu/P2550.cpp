#include<iostream>
using namespace std;
bool vis[40];
int reward[10];
int main() {
	int n;
	cin>>n;
	for(int i=1,x;i<=7;i++) {
		cin>>x;
		vis[x]=1;
	}
	for(int i=1;i<=n;i++) {
		int cnt=0;
		for(int j=1,x;j<=7;j++) {
			cin>>x;
			if(vis[x]) cnt++;
		}
		reward[7-cnt]++;
	}
	for(int i=0;i<=6;i++) cout<<reward[i]<<' ';
	return 0;
}