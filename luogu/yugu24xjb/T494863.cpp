/*********************************************************************
    程序名: T494863.cpp
    版权: 
    作者: tin_ingot
    日期: 2024-08-15 20:13 
    说明: 
*********************************************************************/
#include <iostream>
using namespace std;

int main() {
	int n,a,b;
	cin>>n>>a>>b;
	for(int i=n/b;i>=0;i--) {
		int y=n-i*b;
		int j=y/a;
		if(i*b+j*a==n) {
			cout<<j<<' '<<i;
			return 0;
		}
	}
	puts("NO");
	return 0;
}