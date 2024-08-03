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
	int dot=0,colon=0;
	for(int i=0;i<str.length();i++) {
		if(str[i]=='.') dot++;
		else if(str[i]==':') colon++;
	}
	if(dot!=3 || colon!=1) return 0;
	int a,b,c,d,e;
	sscanf(str.c_str(),"%d.%d.%d.%d:%d",&a,&b,&c,&d,&e);
	char s[35];
	sprintf(s,"%d.%d.%d.%d:%d",a,b,c,d,e);
	if(strcmp(s,str.c_str())) return 0;
	return judge(a,255) && judge(b,255) && judge(c,255) && judge(d,255) && judge(e,65535);
}
int main() {
	// freopen("network4.in","r",stdin);
	// freopen("network4.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) {
		string op,ad;
		cin>>op>>ad;
		if(op=="Server") {
			if(!check(ad)) puts("ERR");
			else if(!mp.count(ad)) {
				mp[ad]={ad,i};
				puts("OK");
			}
			else puts("FAIL");
		} else {
			if(!check(ad)) puts("ERR");
			else if(!mp.count(ad)) puts("FAIL");
			else if(mp[ad].first==ad) cout<<mp[ad].second<<'\n';
			else puts("FAIL");
		}
	}
	return 0;
}