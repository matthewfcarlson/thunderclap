// Same code shape as 0x0010b980 (propagated; names are from that function)
class RefObj_151e90 {
  public:
    virtual void AddRef();
    virtual void Release();
};

class ActionBase_151e90 {
  public:
    ActionBase_151e90();
    virtual void Update();
    char pad[0x18];
};

class HitDamageAction_151e90 : public ActionBase_151e90 {
  public:
    int mTarget;
    RefObj_151e90* mObj;
    HitDamageAction_151e90(int target, RefObj_151e90* obj);
    virtual void Execute();
};

HitDamageAction_151e90::HitDamageAction_151e90(int target, RefObj_151e90* obj) {
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
