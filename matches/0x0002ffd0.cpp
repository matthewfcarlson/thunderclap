#include "decls/address.h"
#include "decls/data/game/global.h"
struct CtorV_001d0480 {
    CtorV_001d0480(void*, int);
    virtual void v_001d0480();
};
class Function_2ffd0 : public CtorV_001d0480 {
  public:
    Function_2ffd0(void* a) : CtorV_001d0480(a, 1) { }
};
class Method1 : public Function_2ffd0 {
  public:
    virtual void invoke();
    char pad[0xc];
    unsigned char flagA;
    char pad2[7];
    unsigned char flagB;
    char pad3[3];
    void* data;
    Method1(void* a, void* c) : Function_2ffd0(a) {
        data = c;
        flagB = FUN_001d04d0(((char*)&DAT_0048e100));
        flagA = FUN_001d04d0(((char*)&DAT_0048e0e4));
    }
};
class Closure1 : public Method1 {
  public:
    virtual void invoke();
    void* extra;
    Closure1(void* a, void* b, void* c);
};
Closure1::Closure1(void* a, void* b, void* c) : Method1(a, c) {
    extra = b;
}
