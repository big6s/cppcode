//一艘船以 v0​ 的速度向距离为 S 的目的地行驶，在给出的时间点 T[i]​​，这艘船会掉头行驶，掉头行驶的初始速度是 v1​，初始时间是 t1​。之后的每一次掉头，速度会在前一次的基础上增加 v2，时间会在前一次的基础上增加 t2​。如果调头行驶时到了出发点，剩下的时间就原地不动。求到达目的地的时间（向上取整）。

#include <iostream>
#include <algorithm>
using ll=long long;
using namespace std;

int main() {
	//pos表示当前位置，nt表示当前时间，v表示当前速度，t表示当前时间间隔
	int s,v0,v1,t1,v2,t2,pos=0,nt=0,n;
	cin>>s>>v0>>v1>>t1>>v2>>t2>>n;
	int v=v1-v2,t=t1-t2; //v表示当前速度，t表示当前时间间隔
	while(n--) {
		int T;
		cin>>T;
		ll np=pos+1ll*v0*(T-nt); //np表示下一次位置
		if(np>=s) {
			ll rds=s-pos;
			nt+=(rds-1)/v0+1;
			pos=s;
			break;
		}
		pos=np;
		v+=v2, t+=t2;
		nt=T+t;
		pos-=1ll*v*t;
		if(pos<0) pos=0;
	}
	if(pos<s) {
		ll rds=s-pos;
		nt+=(rds-1)/v0+1;
	}
	int day=nt/86400+1; //86400s=24h
	nt%=86400;
	int hour=nt/3600;
	nt%=3600;
	int minute=nt/60, second=nt%60;
	printf("202304%02dat%02d:%02d:%02d\n",day,hour,minute,second);
	return 0;
}