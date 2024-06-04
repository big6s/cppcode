#include <bits/stdc++.h>
using namespace std;
const int N = 100000 + 10;
string s[N];
int f[N], n, ans;
int main() {
    freopen("code.in", "r", stdin);
    freopen("code.out", "w", stdout);
    scanf("%d",&n);
    for (int i = 1; i <= n; i++) {
        scanf("%s",s[i].c_str());
        f[i] = 1;
        for (int j = i - 1; j >= 1; j--)
            if (!s[i].find(s[j]))
                f[i] = max(f[j] + 1, f[i]);
        ans = max(f[i], ans);
    }
    printf("%d",ans);
    return 0;
}