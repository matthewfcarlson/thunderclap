// Same code shape as 0x0001db40 (propagated; names are from that function)
struct Obj_20cd0 {
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
    Obj_20cd0* mObj;
    int mValue;
};
class CDrainHealthAction : public CAction {
  public:
    CDrainHealthAction(Obj_20cd0*, int);
    virtual void V0();
};
CDrainHealthAction::CDrainHealthAction(Obj_20cd0* arg, int value) {
    *(int*)this = (int)&VBase;
    mObj = 0;
    if (arg)
        arg->F();
    if (mObj)
        mObj->G();
    mObj = arg;
    mValue = value;
    *(int*)this = (int)&VDerived;
}
void CDrainHealthAction::V0() {}