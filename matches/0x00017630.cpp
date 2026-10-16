#include "gen/global.h"

class CAction_17630 {
  public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual bool vfunc_6(int);
    virtual void a7();
    virtual void a8();
};
class Obj_17630 {
  public:
    void* first();
    void* second();
    void third(int);
};

bool CRageModeAction::vfunc_6(int arg) {
    Obj_17630* x = (Obj_17630*)(*(Obj_17630 * *)&this->f_1c)->first();
    x = (Obj_17630*)x->second();
    x->third(this->f_20);
    return true;
}
