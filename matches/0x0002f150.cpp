#include "decls/address.h"
extern char DAT_0048e100[];
extern char DAT_0048e134[];
class Function_2f150 {
  public:
    Function_2f150(void*, int);
    virtual void v();
};
class Method1 : public Function_2f150 {
  public:
    char pad0[12];
    char a;
    char pad1[7];
    char b;
    char pad2[3];
    int value;
    Method1(void* p, int x) : Function_2f150(p, 1) {
        value = x;
        b = FUN_001d04d0(DAT_0048e100);
        a = FUN_001d04d0(DAT_0048e134);
    }
    virtual void v();
};
class Closure1 : public Method1 {
  public:
    int value2;
    Closure1(void* p, int n, int x);
    virtual void v();
};
Closure1::Closure1(void* p, int n, int x) : Method1(p, x) {
    value2 = n;
}
