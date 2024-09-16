#include<iostream>
using ll = long long;
using namespace std;
ll c10,c30;
int main() {
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) {
		int a;
		cin>>a;
		int k=a/30, p=a%30;
		if(!p) c30+=k;
		else if(0<p && p<=10) c30+=k, c10++;
		else if(10<p && p<=20) c30+=k, c10+=2;
		else /*if(20<p && p<30)*/ c30+=k+1;
	}
	cout<<c30<<' '<<c10;
	return 0;
}
