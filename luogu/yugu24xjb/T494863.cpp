/*********************************************************************
    ������: T494863.cpp
    ��Ȩ: 
    ����: tin_ingot
    ����: 2024-08-15 20:13 
    ˵��: 
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