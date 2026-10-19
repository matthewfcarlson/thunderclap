#include "decls/address.h"
class CSPManager;
struct CtorV_001d0480 {
    CtorV_001d0480(void*, int);
    virtual void v_001d0480();
};
extern const char a[];
extern const char b[];
class Base : public CtorV_001d0480 {
  public:
    Base(void* p) : CtorV_001d0480(p, 1) { }
};
class Method1 : public Base {
  public:
    virtual void invoke(float);
    char pad[0x0c];
    char x;
    char pad2[7];
    char y;
    char pad3[3];
    void* obj;
    Method1(void*, void*);
};
class Closure1 : public Method1 {
  public:
    virtual void invoke(float);
    void* data;
    Closure1(void*, void*, void*);
};
Method1::Method1(void* p, void* f) : Base(p) {
    obj = f;
    y = FUN_001d04d0(a);
    x = FUN_001d04d0(b);
}
Closure1::Closure1(void* p, void* f, void* q) : Method1(p, q) {
    data = f;
}