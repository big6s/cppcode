#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int t;
	cin>>t;
	while (t--) {
		int n,id;
		double mi=1e9;
		cin>>n;
		for (int i = 1; i <= n; i++) {
			int x1,y1,x2,y2,s;
			cin>>x1>>y1>>x2>>y2>>s;
			double cost=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))*s/abs(x1-x2);
			if (cost<mi) {
				mi=cost;
				id=i;
			}
		}
		cout<<id<<'\n';
	}
	return 0;
}