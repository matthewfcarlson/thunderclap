#include "decls/address.h"
class CRenderManager;
extern const char g1[], g2[];
class Function_1ba850 {
  public:
    Function_1ba850(void*, int);
    virtual void f();
};
class Method1 : public Function_1ba850 {
  public:
    virtual void f();
    char pad[12];
    unsigned char a;
    char pad2[7];
    unsigned char b;
    char pad3[3];
    CRenderManager* mgr;
    Method1(void* p, CRenderManager* m) : Function_1ba850(p, 1) {
        mgr = m;
        b = FUN_001d04d0(g1);
        a = FUN_001d04d0(g2);
    }
};
class Closure1 : public Method1 {
  public:
    virtual void f();
    void* closure;
    Closure1(void*, void*, CRenderManager*);
};
Closure1::Closure1(void* p, void* q, CRenderManager* m) : Method1(p, m) {
    closure = q;
}