// Same code shape as 0x0001db40 (propagated; names are from that function)
#include "compat/ptr.h"
struct Obj_1dbc0 {
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
    Obj_1dbc0* mObj;
    int mValue;
};
class CComboTimerAction_1dbc0 : public CAction {
  public:
    CComboTimerAction_1dbc0(Obj_1dbc0*, int);
    virtual void V0();
};
CComboTimerAction_1dbc0::CComboTimerAction_1dbc0(Obj_1dbc0* arg, int value) {
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
void CComboTimerAction_1dbc0::V0() {}