// Same code shape as 0x0001db40 (propagated; names are from that function)
#include "compat/ptr.h"
struct Obj_20ad0 {
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
    Obj_20ad0* mObj;
    int mValue;
};
class CAlertStatusAction_20ad0 : public CAction {
  public:
    CAlertStatusAction_20ad0(Obj_20ad0*, int);
    virtual void V0();
};
CAlertStatusAction_20ad0::CAlertStatusAction_20ad0(Obj_20ad0* arg, int value) {
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
void CAlertStatusAction_20ad0::V0() {}