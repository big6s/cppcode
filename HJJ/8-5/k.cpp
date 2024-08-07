/*
h2储存整个序列的前i个最小值，
保证h2的大小永远等于i，大根堆，根即为每次需要Get的值

h1储存序列剩下部分的值，小根堆

每一次操作就是先按照u(i)（在我的代码里用的是b[i]）Put(a[j])进到h1

然后因为有u的存在，所以往h2 Put一个数，即为h1的最小值

但是这时候有可能h1中会有比h2任何一个节点小的节点，这样的h2是不符合规定的，于是反复判断h1和h2的根节点（一个是h1最小，一个是h2最大），如果h1的根节点小于h2的根节点，则取出h1和h2的根节点，然后将h1的根节点Put进h2，h2的根节点Put进h1，直到h2的根节点小于h1为止
输出h2
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std; 
const int N = 500000 + 3;
priority_queue<int,vector<int>,greater<int> >h1; // 小根堆 
priority_queue<int> h2;// 大根堆
int a[N],u[N];
int main() {
	int m,n;
	cin>>m>>n;
	for(int i=1;i<=m;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>u[i];
	int p=0;
	for(int i=1;i<=n;i++) {
		while(p<u[i]) {
			p++;
			h2.push(a[p]);
			h1.push(h2.top());
			h2.pop();
		}
		cout<<h1.top()<<'\n';
		h2.push(h1.top());
		h1.pop();
	}
	return 0;
}
