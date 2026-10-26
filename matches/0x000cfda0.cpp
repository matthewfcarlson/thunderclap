#include "decls/data/game/global.h"
// data: gA_cfda0 = DAT_0048e134

extern "C" unsigned char __cdecl lookup(const void*);
class Function_cfda0 {
  public:
    virtual void invoke();
    Function_cfda0(int, int);
};
class Method2_cfda0 : public Function_cfda0 {
  public:
    virtual void invoke();
    char pad[12];
    unsigned char a;
    unsigned char b;
    char pad2[6];
    unsigned char c;
    char pad3[3];
    int m;
    Method2_cfda0(int x, int y) : Function_cfda0(x, 2) {
        m = y;
        c = lookup(((int*)&DAT_0048e134));
        a = lookup(((int*)&DAT_0048e134));
        b = lookup(((int*)&DAT_0048e0f0));
    }
};
class Closure2_cfda0 : public Method2_cfda0 {
  public:
    virtual void invoke();
    int n;
    Closure2_cfda0(int x, int y, int z);
};
Closure2_cfda0::Closure2_cfda0(int x, int y, int z) : Method2_cfda0(x, z) {
    n = y;
}
