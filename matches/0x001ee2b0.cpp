#include "decls/address.h"
#include "decls/data/game/global.h"
struct CtorV_001d0480 {
    CtorV_001d0480(void*, int);
    virtual void v_001d0480();
};
class Base : public CtorV_001d0480 {
  public:
    Base(void* p) : CtorV_001d0480(p, 1) { }
};
class Closure1_1ee2b0 : public Base {
  public:
    virtual void Invoke(bool);
    char pad[12];
    char a;
    char pad2[7];
    char b;
    char pad3[3];
    void* owner;
    Closure1_1ee2b0(void* p, void* r);
};
class Closure1 : public Closure1_1ee2b0 {
  public:
    virtual void Invoke(bool);
    void* extra;
    Closure1(void* p, void* q, void* r);
};
Closure1_1ee2b0::Closure1_1ee2b0(void* p, void* r) : Base(p) {
    owner = r;
    b = FUN_001d04d0(((const char*)&DAT_0048e100));
    a = FUN_001d04d0(((const char*)&DAT_0048e0e4));
}
Closure1::Closure1(void* p, void* q, void* r) : Closure1_1ee2b0(p, r) {
    extra = q;
}
