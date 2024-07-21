#include <iostream>
using namespace std;

int main() {
	string s,t;
	cin>>s>>t;
	int i=0,j=0,l=0;
	while(i<s.size() && j<t.size()) {
		if(s[i]==t[j] || s[i]=='?' || t[j]=='?') {
			if(!l) l=i;
			j++;
		}
		else {
			if(l) cout<<l+1<<' '<<i<<'\n';
			l=0;
		}
		i++;
	}
	if(i<s.size() || j<t.size()) {
		if(l) cout<<l+1<<' '<<i<<'\n';
	}
	else {
		if(l) cout<<l+1<<' '<<s.size()<<'\n';
	}
	return 0;
}