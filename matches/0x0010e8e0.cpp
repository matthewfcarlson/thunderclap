#include "compat/ptr.h"
class FormationReadyCondition {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    int pad4;
    int pad8;
    int padc;
    int m10;
    FormationReadyCondition* vfunc_5(int);
    void Cleanup();
};
extern "C" void __cdecl helper(hulk_intptr);
extern "C" void __cdecl helper2(FormationReadyCondition*);
extern int formation_vtable;
FormationReadyCondition* FormationReadyCondition::vfunc_5(int flag) {
    *(volatile hulk_intptr*)this = (hulk_intptr)&formation_vtable;
    helper(m10);
    Cleanup();
    if (flag & 1)
        helper2(this);
    return this;
}