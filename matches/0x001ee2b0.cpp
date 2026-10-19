#include "decls/address.h"
struct CtorV_001d0480 {
    CtorV_001d0480(void*, int);
    virtual void v_001d0480();
};
extern const char g1[];
extern const char g2[];
class Base : public CtorV_001d0480 {
  public:
    Base(void* p) : CtorV_001d0480(p, 1) { }
};
class Method1 : public Base {
  public:
    virtual void Invoke(bool);
    char pad[12];
    char a;
    char pad2[7];
    char b;
    char pad3[3];
    void* owner;
    Method1(void* p, void* r);
};
class Closure1 : public Method1 {
  public:
    virtual void Invoke(bool);
    void* extra;
    Closure1(void* p, void* q, void* r);
};
Method1::Method1(void* p, void* r) : Base(p) {
    owner = r;
    b = FUN_001d04d0(g1);
    a = FUN_001d04d0(g2);
}
Closure1::Closure1(void* p, void* q, void* r) : Method1(p, r) {
    extra = q;
}
