#include <bits/stdc++.h>
using namespace std;
long long INF=1ll<< 32;
stack<long long>s;
char op[5];
int main(){
	ios::sync_with_stdio(false);
	long long l, ans =0;
	cin >>l;
	s.push(1);
	for(int i=1;i<= l; i++){
		int x;
		cin >> op;
		if(op[0]== 'a')
			ans += s.top();
		else if(op[0]=='f'){
			cin >>x;
			s.push(min(INF,s.top()*x));
		}else
			s.pop();
	}
	if(ans < INF)
		cout<<ans<<endl;
	else
		cout << "OVERFLOW!!!"<< endl;
	return 0;
}
