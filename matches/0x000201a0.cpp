// Same code shape as 0x0001db40 (propagated; names are from that function)
#include "compat/ptr.h"
struct Obj_201a0 {
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
    Obj_201a0* mObj;
    int mValue;
};
class CStageAction_201a0 : public CAction {
  public:
    CStageAction_201a0(Obj_201a0*, int);
    virtual void V0();
};
CStageAction_201a0::CStageAction_201a0(Obj_201a0* arg, int value) {
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
void CStageAction_201a0::V0() {}