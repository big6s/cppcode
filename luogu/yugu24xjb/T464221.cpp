#include<iostream>
using namespace std;
const int N=1e3+3;
char f[N][N];
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

  template <class T>
  void read(T &x) {
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

  void read(char *s) {
    char ch = gc();
    for (; blank(ch); ch = gc());
    for (; !blank(ch); ch = gc()) *s++ = ch;
    *s = 0;
  }

  void read(char &c) { for (c = gc(); blank(c); c = gc()); }

  void push(const char &c) {
    if (pp - pbuf == MAXSIZE) fwrite(pbuf, 1, MAXSIZE, stdout), pp = pbuf;
    *pp++ = c;
  }
	void write(char *x,char y) {
		char *p=x;
		while(*p) push(*p),p++;
		push(y);
  }
  template <class T>
  void write(T x) {
    if (x < 0) x = -x, push('-');  // ¸ºÊýÊä³ö
    static T sta[35];
    T top = 0;
    do {
      sta[top++] = x % 10, x /= 10;
    } while (x);
    while (top) push(sta[--top] + '0');
  }

  template <class T>
  void write(T x, char lastChar) {
    write(x), push(lastChar);
  }
} io;
int main() {
	int n,m,q;
	io.read(n),io.read(m),io.read(q);
	for(int i=1;i<=n;i++) {
		io.read(f[i]+1);
	}
	while(q--) {
		int op,x,y;
		io.read(op);
		io.read(x);
		io.read(y);
		if(op==1) {
			if(x==y) continue;
			swap(f[x],f[y]);
		}
		else if(op==2) {
			if(x==y) continue;
			for(int i=1;i<=n;i++) {
				swap(f[i][x],f[i][y]); //+1
			}
		}
		else {
			io.write(f[x][y]^48,'\n');
		}
	}
	for(int i=1;i<=n;i++) {
		io.write(f[i]+1,'\n');
	}
	return 0;
}