#include "compat/ptr.h"
class Target_1c16a0 {
    char pad[0xbc];
    hulk_intptr value;

  public:
    void f(void*);
};
class Other_1c16a0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void g();
    virtual void h();
    virtual void i();
    virtual void j(void*, int);
};
void Target_1c16a0::f(void* p) {
    if (p)
        ((Other_1c16a0*)p)->j((void*)value, 0);
}