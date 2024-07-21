#include<iostream>
using namespace std;
const int N=100000+10;
const double inf=1e10,eps=1e-5;
double sum[N];
int n,L,a[N];
int main()
{
  cin>>n>>L;
  for(int i=1; i<=n; i++) cin>>a[i];
  double l=0,r=2000;
  while(r-l>eps)
  {
    double mid=(l+r)/2;
    for(int i=1; i<=n; i++) sum[i]=sum[i-1]+a[i]-mid;
    double ans=-inf,mi=inf;
    for(int i=L; i<=n; i++)
    {
      mi=min(mi,sum[i-L]);
      ans=max(ans,sum[i]-mi);
    }
    if(ans>=0) l=mid;
    else r=mid;
  }
  cout<<int(r*1000);
  return 0;
}