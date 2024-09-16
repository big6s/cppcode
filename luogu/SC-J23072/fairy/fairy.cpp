#include <iostream>
#include <cstring>
using namespace std;
const int N=1010;
char s[N],t[N];
bool f[N][N];
bool isMatch() {
	f[0][0]=1;
	int n=strlen(s+1), m=strlen(t+1);
	for(int i=1;s[i];i++) {
		for(int j=1;t[j];j++) {
			char x=s[i], y=t[j];
			if(x==y && x!='_' && x!='%') f[i][j]|=f[i-1][j-1];
			if(x=='%' || y=='%') f[i][j]|=f[i-1][j-1];
			if(x=='_') f[i][j] |= f[i][j-1] | f[i-1][j-1];
			if(y=='_') f[i][j] |= f[i-1][j] | f[i-1][j-1];
		}
	}
	return f[n][m];
}
int main() {
	int T;
	cin>>T;
	while(T--) {
		memset(f,0,sizeof f);
		cin>>(s+1)>>(t+1);
		if(isMatch()) cout<<"Y\n";
		else cout<<"N\n";
	}
	return 0;
}
