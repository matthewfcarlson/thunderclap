// Same code shape as 0x0010b980 (propagated; names are from that function)
class RefObj_151b30 {
  public:
    virtual void AddRef();
    virtual void Release();
};

class Action_151b30 {
  public:
    Action_151b30();
    virtual void Update();
    char pad[0x18];
};

class NoHitPushbackAction_151b30 : public Action_151b30 {
  public:
    int mTarget;
    RefObj_151b30* mObj;
    NoHitPushbackAction_151b30(int target, RefObj_151b30* obj);
    virtual void Execute();
};

NoHitPushbackAction_151b30::NoHitPushbackAction_151b30(int target, RefObj_151b30* obj) {
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
