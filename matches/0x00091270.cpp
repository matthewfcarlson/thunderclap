#include "decls/address.h"
struct CtorV_001d0480 {
    CtorV_001d0480(const char*, int);
    virtual void v_001d0480();
};
extern const char DAT_0048e0f0[];
extern const char DAT_0048e134[];
class Function_91270 : public CtorV_001d0480 {
  public:
    Function_91270(const char* s) : CtorV_001d0480(s, 1) { }
    char pad[0xc];
    unsigned char f10;
    char pad2[7];
    unsigned char f18;
    char pad3[3];
    int f1c;
};
class Method1 : public Function_91270 {
  public:
    virtual void invoke();
    Method1(const char* s, int n) : Function_91270(s) {
        f1c = n;
        f18 = FUN_001d04d0(DAT_0048e0f0);
        f10 = FUN_001d04d0(DAT_0048e134);
    }
};
class Closure1 : public Method1 {
  public:
    virtual void invoke();
    int f20;
    Closure1(const char* s, int n, int m);
};
Closure1::Closure1(const char* s, int n, int m) : Method1(s, m), f20(n) {}