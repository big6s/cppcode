#include <iostream>
using namespace std;

int main() {
	string s;
	cin>>s;
	int up=0,lw=0;
	for(auto i:s) {
		if(i>='a'&&i<='z') lw++;
		else up++;
	}
	if(up>lw) {
		for(auto &i:s) {
			if(i>='a'&&i<='z') i=i-'a'+'A';
			cout<<i;
		}
	}
	else {
		for(auto &i:s) {
			if(i>='A'&&i<='Z') i=i-'A'+'a';
			cout<<i;
		}
	}
	return 0;
}
