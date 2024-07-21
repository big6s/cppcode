#include <bits/stdc++.h>
using namespace std;
const int N=1e5+3;
int n, ans, top, k;
int t[N],df[N]; //df差分,t气温
struct node {
	int v, sum;
	friend bool operator < (node a,node b) {
		return a.sum>b.sum;
	}
}s[N];
int main(){
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>t[i];
	}
	t[n+1]=1e9;
	int sum=0, mx=0;
	for(int i=1; i<=n+1; i++) {
		if(t[i]<0) ++sum;
		else if(sum){
			s[++top]={i-sum, sum};
			sum=0;
		}
	}
	sort(s+1, s+top+1);
	mx=s[1].sum;
	for(int i=1; i<=top; i++) { //求差分
		df[s[i].v]--;
		if(s[i].v-s[i].sum*2>1) df[s[i].v-s[i].sum*2]++;
		else df[1]++;
	}
	for(int i=1;i<=n;i++) df[i]+=df[i-1]; //求前缀和
	for(int i=1;i<=n;i++) df[i]=bool(df[i]);
	for(int i=1;i<=n;i++) df[i]+=df[i-1];
	for(int i=1;i<=top;i++) {
		if(s[i].sum<mx) break;
		k=max(k,(s[i].v>s[i].sum*3?s[i].sum*3:s[i].v-1)-(df[s[i].v-1]-df[max(s[i].v-s[i].sum*3-1, 0)]));
	}
	printf("%d", df[n]+k);
	return 0;
}