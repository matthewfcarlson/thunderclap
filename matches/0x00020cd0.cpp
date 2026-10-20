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
class CMotionHitGroundHeightAction_20cd0 : public CAction {
  public:
    CMotionHitGroundHeightAction_20cd0(Obj_20cd0*, int);
    virtual void V0();
};
CMotionHitGroundHeightAction_20cd0::CMotionHitGroundHeightAction_20cd0(Obj_20cd0* arg, int value) {
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
void CMotionHitGroundHeightAction_20cd0::V0() {}