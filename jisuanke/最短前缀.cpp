#include <iostream>
#include <map>
using namespace std;
int n;
string s[1010];
map<string,int> mp;
int main() {
	while(cin>>s[++n]);
	for(int i=1;i<=n;i++) {
		string t="";
		for(int j=0;j<s[i].size();j++) {
			mp[t+=s[i][j]]++;
		}
	}
	for(int i=1;i<=n;i++) {
		string t="";
		for(int j=0;j<s[i].size();j++) {
			t+=s[i][j];
			if(mp[t]==1 || j+1==s[i].size()) {
				cout<<s[i]<<' '<<t<<'\n';
				break;
			}
		}
	}
	return 0;
}
