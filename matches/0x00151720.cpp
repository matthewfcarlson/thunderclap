// Same code shape as 0x0010b980 (propagated; names are from that function)
class RefObj_151720 {
  public:
    virtual void AddRef();
    virtual void Release();
};

class ActionBase_151720 {
  public:
    ActionBase_151720();
    virtual void Update();
    char pad[0x18];
};

class HitPauseAction_151720 : public ActionBase_151720 {
  public:
    int mTarget;
    RefObj_151720* mObj;
    HitPauseAction_151720(int target, RefObj_151720* obj);
    virtual void Execute();
};

HitPauseAction_151720::HitPauseAction_151720(int target, RefObj_151720* obj) {
    int* p = &mTarget;
    *p = 0;
    mObj = 0;
    mTarget = target;
    if (obj) {
        obj->AddRef();
    }
    if (mObj) {
        mObj->Release();
    }
    mObj = obj;
}
