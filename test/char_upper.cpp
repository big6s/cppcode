#include<stdio.h>
#include<ctype.h>
const int N=100010;
char s[N];
int main() {
//	scanf("%s",s);
	fgets(s,N-10,stdin);
	for(int i=0;s[i];i++) {
		putchar(toupper(s[i]));
	}
	return 0;
}