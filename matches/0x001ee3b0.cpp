#include "decls/address.h"
#include "decls/data/game/global.h"
struct CtorV_001d0480 {
    CtorV_001d0480(void*, int);
    virtual void v_001d0480();
};
class Base : public CtorV_001d0480 {
  public:
    Base(void* x) : CtorV_001d0480(x, 1) { }
};
class Closure1_1ee3b0 : public Base {
  public:
    virtual void f();
    char pad[12];
    unsigned char a;
    char pad2[7];
    unsigned char b;
    char pad3[3];
    void* p;
    Closure1_1ee3b0(void*, void*, void*);
};
class Closure1 : public Closure1_1ee3b0 {
  public:
    virtual void f();
    void* q;
    Closure1(void*, void*, void*);
};
Closure1::Closure1(void* x, void* y, void* z) : Closure1_1ee3b0(x, y, z) {
    q = y;
}
Closure1_1ee3b0::Closure1_1ee3b0(void* x, void* y, void* z) : Base(x) {
    p = z;
    b = FUN_001d04d0(((char*)&DAT_0048e100));
    a = FUN_001d04d0(((char*)&DAT_0049cad8));
}