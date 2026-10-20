// Same code shape as 0x0001db40 (propagated; names are from that function)
#include "compat/ptr.h"
struct Obj_1f4e0 {
    virtual void F();
    virtual void G();
};
extern int VBase;
extern int VDerived;
class CAction {
  public:
    CAction();
    virtual void V0();
    virtual void V1();
    char pad[0x18];
    Obj_1f4e0* mObj;
    int mValue;
};
class CInvincibleAction_1f4e0 : public CAction {
  public:
    CInvincibleAction_1f4e0(Obj_1f4e0*, int);
    virtual void V0();
};
CInvincibleAction_1f4e0::CInvincibleAction_1f4e0(Obj_1f4e0* arg, int value) {
    *(hulk_intptr*)this = (hulk_intptr)&VBase;
    mObj = 0;
    if (arg)
        arg->F();
    if (mObj)
        mObj->G();
    mObj = arg;
    mValue = value;
    *(hulk_intptr*)this = (hulk_intptr)&VDerived;
}
void CInvincibleAction_1f4e0::V0() {}