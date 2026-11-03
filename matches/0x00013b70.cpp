#include "gen/global.h"
#include "gen/owners.h"

class CAction_13b70 {
  public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual bool vfunc_7(int);
    virtual void a8();
};
struct X_13b70 {
    X_13b70* f2();
    int f3(int);
};

bool CClimbingAction::vfunc_7(int ) {
    X_13b70* x = (X_13b70*)(*(void * *)&this->f_1c);
    x = ((X_13b70 *)((owners::Object_592a0 *)x)->FUN_000592a0());
    x = x->f2();
    x->f3(4);
    return true;
}
