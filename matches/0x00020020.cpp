// Same code shape as 0x0001db40 (propagated; names are from that function)
#include "compat/ptr.h"
struct Obj_20020 {
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
    Obj_20020* mObj;
    int mValue;
};
class CUninterruptibleAction_20020 : public CAction {
  public:
    CUninterruptibleAction_20020(Obj_20020*, int);
    virtual void V0();
};
CUninterruptibleAction_20020::CUninterruptibleAction_20020(Obj_20020* arg, int value) {
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
void CUninterruptibleAction_20020::V0() {}