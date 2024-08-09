#include <iostream>
#include <map>
using ll = long long;
using namespace std;
struct IO {
#define MAXSIZE (1 << 20)
#define isdigit(x) (x >= '0' && x <= '9')
  char buf[MAXSIZE], *p1, *p2;
  char pbuf[MAXSIZE], *pp;
  IO() : p1(buf), p2(buf), pp(pbuf) {}
  ~IO() { fwrite(pbuf, 1, pp - pbuf, stdout); }
  char gc() {
    if (p1 == p2) p2 = (p1 = buf) + fread(buf, 1, MAXSIZE, stdin);
    return p1 == p2 ? ' ' : *p1++;
  }
  bool blank(char ch) {
    return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
  }
  template <class T> void read(T &x) {
    double tmp = 1;
    bool sign = 0;
    x = 0;
    char ch = gc();
    for (; !isdigit(ch); ch = gc())
      if (ch == '-') sign = 1;
    for (; isdigit(ch); ch = gc()) x = x * 10 + (ch - '0');
    if (ch == '.')
      for (ch = gc(); isdigit(ch); ch = gc())
        tmp /= 10.0, x += tmp * (ch - '0');
    if (sign) x = -x;
  }
  void push(const char &c) {
    if (pp - pbuf == MAXSIZE) fwrite(pbuf, 1, MAXSIZE, stdout), pp = pbuf;
    *pp++ = c;
  }
  template <class T> void write(T x) {
    static T sta[35];
    T top = 0;
    do {
      sta[top++] = x % 10, x /= 10;
    } while (x);
    while (top) push(sta[--top] + '0');
  }
} io;
map<ll, ll> f;
ll fun(ll x) {
	if(f.count(x)) return f[x];
	if(!x) return f[x]=1;
	return f[x]=fun(x>>1)+fun(x/3);
}
int main() {
	int n;
	io.read(n);
	io.write(fun(n));
	return 0;
}