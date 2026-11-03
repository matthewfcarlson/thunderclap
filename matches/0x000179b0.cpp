#include "gen/global.h"
#include "gen/owners.h"

struct Manager_179b0;
struct Ctx_179b0 {
};
struct Manager_179b0 {
    Manager_179b0* g();
};
class X_179b0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8(int);
};

bool CAlertStatusAction::vfunc_6(int ) {
    Manager_179b0* p = ((Manager_179b0 *)((owners::Object_592a0 *)((*(Ctx_179b0 * *)&this->f_1c)))->FUN_000592a0());
    p = p->g();
    X_179b0* x = *(X_179b0**)((char*)p + 0x1ca0);
    if (x)
        x->f8(this->f_20);
    return false;
}
