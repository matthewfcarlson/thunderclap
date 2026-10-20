#include "decls/address.h"
typedef unsigned char byte;
struct CtorV_001d0480 {
    CtorV_001d0480(void*, int);
    virtual void v_001d0480();
};
extern const char a[], b[];
class Base : public CtorV_001d0480 {
  public:
    Base(void* p) : CtorV_001d0480(p, 1) { }
};
class Closure1_1f20b0 : public Base {
  public:
    virtual void Invoke();
    char pad[0x0c];
    byte x;
    char pad2[7];
    byte y;
    char pad3[3];
    void* obj;
    Closure1_1f20b0(void*, void*);
};
class Closure1 : public Closure1_1f20b0 {
  public:
    virtual void Invoke();
    void* extra;
    Closure1(void*, void*, void*);
};
Closure1::Closure1(void* p, void* q, void* r) : Closure1_1f20b0(p, r) {
    extra = q;
}
Closure1_1f20b0::Closure1_1f20b0(void* p, void* q) : Base(p) {
    obj = q;
    y = FUN_001d04d0(a);
    x = FUN_001d04d0(b);
}
