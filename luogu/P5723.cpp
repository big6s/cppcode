#include<iostream>
using namespace std;
const int N=1e5+3;
bool vis[N]; //ºÏÊý
void init(int N) {
	for(int i=2;i*i<N;i++) {
		if(!vis[i]) {
			for(int j=i*2;j<N;j+=i) {
				vis[j]=1;
			}
		}
	}
}
int main() {
	int L,f=0,u=0;
	cin>>L;
	init(L);
	for(int i=2;u+i<=L && i<=L;i++) {
		if(!vis[i]) {
			cout<<i<<'\n';
			u+=i;
			f++;
		}
	}
	cout<<f;
	return 0;
}