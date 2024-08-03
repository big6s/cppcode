#include<iostream>
#include<cstring>
#include<map>
#include<algorithm>
using namespace std;
map<string,pair<string,int> > mp;
bool judge(int x,int mx) {
	return x>=0 && x<=mx;
}
bool check(string str) {
	char s[30];
	strcpy(s,str.c_str());
	int a,b,c,d,e;
	sscanf(s,"%d.%d.%d.%d:%d",&a,&b,&c,&d,&e);
	return judge(a,255) && judge(b,255) && judge(c,255) && judge(d,255) && judge(e,65535);
}
int main() {
	#ifndef ONLINE_JUDGE
	freopen("network3.in","r",stdin);
	freopen("network3.out","w",stdout);
	#endif
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) {
		string op,ad;
		cin>>op>>ad;
		if(op=="Server") {
			if(!check(ad)) puts("ERR");
			else if(mp[ad].first=="") {
				mp[ad]={ad,i};
				puts("OK");
			}
			else puts("FAIL");
		} else {
			if(!check(ad)) puts("ERR");
			else if(mp[ad].first==ad) cout<<mp[ad].second<<'\n';
			else puts("FAIL");
		}
	}
	return 0;
}