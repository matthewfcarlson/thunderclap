// Same code shape as 0x0010b980 (propagated; names are from that function)
class RefObj_10f8b0 {
  public:
    virtual void AddRef();
    virtual void Release();
};

class ActionBase_10f8b0 {
  public:
    ActionBase_10f8b0();
    virtual void Update();
    char pad[0x18];
};

class AIHistorySetAction_10f8b0 : public ActionBase_10f8b0 {
  public:
    int mTarget;
    RefObj_10f8b0* mObj;
    AIHistorySetAction_10f8b0(int target, RefObj_10f8b0* obj);
    virtual void Execute();
};

AIHistorySetAction_10f8b0::AIHistorySetAction_10f8b0(int target, RefObj_10f8b0* obj) {
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
