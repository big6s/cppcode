#include<iostream>
#include<stack>
using namespace std;
char a[1005];
int sum,k;
stack <int> stk;
int main()
{
	cin>>a;
	for(int i=0;a[i]!='@';i++)
	{
		if(a[i]=='.')
		{
			sum=0,k=1;
			for(int j=i-1;j>=0&&a[j]>='0'&&a[j]<='9';j--) sum=sum+(a[j]-48)*k,k*=10; 
			stk.push(sum);
			continue;
		}
		if(a[i]>='0'&&a[i]<='9') continue;
		sum=stk.top();
		stk.pop(); 
		if(a[i]=='+') sum+=stk.top();
		if(a[i]=='-') sum=stk.top()-sum;
		if(a[i]=='*') sum*=stk.top();
		if(a[i]=='/') sum=stk.top()/sum;
		stk.pop();
		stk.push(sum);
	}
	printf("%d",stk.top());
	return 0;	
}
