// Same code shape as 0x0001db40 (propagated; names are from that function)
struct Obj_20120 {
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
    Obj_20120* mObj;
    int mValue;
};
class CRageModeAction_20120 : public CAction {
  public:
    CRageModeAction_20120(Obj_20120*, int);
    virtual void V0();
};
CRageModeAction_20120::CRageModeAction_20120(Obj_20120* arg, int value) {
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
void CRageModeAction_20120::V0() {}