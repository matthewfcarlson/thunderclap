#include "decls/data/game/global.h"
// data: str1 = DAT_0048e100, str2 = DAT_0048e134

class Function_cf8d0 {
  public:
    Function_cf8d0(int, int);
    virtual void f();
    char pad[12];
};
char __cdecl query(const char*);
class Method1 : public Function_cf8d0 {
  public:
    Method1(int a, int b) : Function_cf8d0(a, 1) {
        v = b;
        c = query(((const char*)&DAT_0048e100));
        d = query(((const char*)&DAT_0048e134));
    }
    virtual void f();
    char d;
    char x[7];
    char c;
    char y[3];
    int v;
};
class Closure1 : public Method1 {
  public:
    Closure1(int a, int b, int z);
    virtual void f();
    int w;
};
Closure1::Closure1(int a, int b, int z) : Method1(a, z) {
    w = b;
}