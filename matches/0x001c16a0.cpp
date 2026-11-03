#include "compat/ptr.h"
#include "gen/owners.h"
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
void owners::Target_1c16a0::FUN_001c16a0(void* p) {
    if (p)
        ((Other_1c16a0*)p)->j((void*)value, 0);
}