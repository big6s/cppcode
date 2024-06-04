#include <bits/stdc++.h>
using namespace std;
const int N = 100000 + 10;
string s[N];
int f[N], n, ans;
int main() {
    freopen("code.in", "r", stdin);
    freopen("code.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for (int i = 1; i <= n; i++) {
        cin>>s[i];
        f[i] = 1;
        for (int j = i - 1; j >= 1; j--)
            if (!s[i].find(s[j]))
                f[i] = max(f[j] + 1, f[i]);
        ans = max(f[i], ans);
    }
    cout<<ans;
    return 0;
}