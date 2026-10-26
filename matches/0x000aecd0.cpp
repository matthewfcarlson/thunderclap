#include "decls/data/game/global.h"
// data: str1_aecd0 = DAT_0048e100, str2 = DAT_0048e134, str3 = DAT_0048e0e4

extern "C" unsigned char parse(const char*);
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
        c = parse(((char*)&DAT_0048e100));
        a = parse(((char*)&DAT_0048e134));
        b = parse(((char*)&DAT_0048e0e4));
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