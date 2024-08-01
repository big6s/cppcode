#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 400;
char s[maxn], s1[20], s2[20];
int main() {
	int len, t1 = 0, t2 = 0, l = 300, r = -1, i;
	scanf("%s",s);
	for(i=0;s[i];i++) {
		if(s[i]==',') { //第一个逗号之后的都是s1
			len=i-1;
			i++;
			break;
		}
	}
	while(s[i]!=',' && s[i]) s1[t1++]=s[i],i++;
	for(;s[i];i++) {
		if(s[i]==',') { //第二个逗号之后的都是s2
			i++;
			break;
		}
	}
	while(s[i]!=',' && s[i]) s2[t2++]=s[i],i++;
	for (int i = 0, j; i < len && i + t1 <= len; ++i) {
		for (j = 0; j < t1; ++j) {
			if (s[i + j] != s1[j]) { break; } //找到第一个匹配s1的位置
		}
		if (j == t1) { //没有找到第一个匹配的位置，说明s1在s中不存在
			l = i + t1;
			break;
		}
	}
	for (int i = l, j; i < len && i + t2 <= len; ++i) {
		for (j = 0; j < t2; ++j) {
			if (s[i + j] != s2[j]) {break;}
		}
		if (j == t2) {r = i - 1;}
	}
	if (r - l < -1) cout<<"-1";
	else cout<<r-l+1;
	return 0;
}