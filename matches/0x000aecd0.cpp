#include "decls/data/game/global.h"
// data: str1_aecd0 = DAT_0048e100, str2 = DAT_0048e134, str3 = DAT_0048e0e4

extern "C" unsigned char FUN_001d04d0(const char*);
class Function_aecd0 {
  public:
    Function_aecd0(void*, int);
    virtual void f();
    char pad[12];
    unsigned char a, b;
    char pad2[6];
    unsigned char c;
    char pad3[3];
    int val;
    int other;
};
class Method2 : public Function_aecd0 {
  public:
    Method2(void* p, int n) : Function_aecd0(p, 2) {
        val = n;
        c = FUN_001d04d0(((char*)&DAT_0048e100));
        a = FUN_001d04d0(((char*)&DAT_0048e134));
        b = FUN_001d04d0(((char*)&DAT_0048e0e4));
    }
    virtual void f();
};
class Closure2 : public Method2 {
  public:
    Closure2(void* p, int m, int n);
    virtual void f();
};
Closure2::Closure2(void* p, int m, int n) : Method2(p, n) {
    other = m;
}