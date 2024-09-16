#include <bits/stdc++.h>
#define int long long
using ll = long long;
using namespace std;

const int N = 510;
int n, cnt, mod;
int fa[N], c[N];

struct edge {
    int u, v, w;
    friend bool operator<(edge x, edge y) {
        return x.w > y.w;
    }
} a[N*N];

ll qpow(ll x,ll y) {
  ll ans=1;
  while(y) {
    if(y&1) ans*=x;
    ans%=mod;
    x*=x;
    x%=mod;
    y>>=1;
  }
  return ans;
}

int find(int x) {
    if (fa[x] != x) return fa[x] = find(fa[x]);
    return x;
}

signed main() {
    cin>>n>>mod;
  for(int i=1;i<=n;i++) {
    cin>>c[i];
  }
  int m=0;
  for(int i=1;i<=n;i++) {
      for(int j=1;j<=n;j++) {
          if(i==j) continue;
          m++;
          a[m].w=(qpow(c[i],c[j])+qpow(c[j],c[i]))%mod;
          a[m].u=i, a[m].v=j;
      }
  }
    int op = 0, ans = 0;
    for (int i = 1; i <= n; i++) fa[i] = i;
    sort(a + 1, a + 1 + m);
    for (int i = 1; i <= m; i++) {
        int u = a[i].u, w = a[i].w, v = a[i].v;
        int fu = find(u), fv = find(v);
        if (fu != fv) fa[fu] = fv, ans += w, op++;
    }
    cout << ans;
    return 0;
}
