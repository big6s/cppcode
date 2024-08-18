#include <iostream>
using namespace std;

int main() {
	freopen("6.txt","w",stdout);
	int x=0;
	for(int i=1;i<=12;i++) {
		int y;
		double sum=0;
		cin>>y;
		x+=y;
		if(x<=310) cout<<3*y<<'\n';
		else {
			if(x<=520) {
				cout<<(x-310)*3.3+(410-x)*3<<'\n';
				sum+=x*3.3;
			}
			else {
				cout<<
			}
		}
		printf("%.1f\n",sum);
	}
	return 0;
}