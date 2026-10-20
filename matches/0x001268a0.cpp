// Same code shape as 0x0010b980 (propagated; names are from that function)
class RefObj_1268a0 {
  public:
    virtual void AddRef();
    virtual void Release();
};

class ActionBase_1268a0 {
  public:
    ActionBase_1268a0();
    virtual void Update();
    char pad[0x18];
};

class TargetClearAction_1268a0 : public ActionBase_1268a0 {
  public:
    int mTarget;
    RefObj_1268a0* mObj;
    TargetClearAction_1268a0(int target, RefObj_1268a0* obj);
    virtual void Execute();
};

TargetClearAction_1268a0::TargetClearAction_1268a0(int target, RefObj_1268a0* obj) {
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
