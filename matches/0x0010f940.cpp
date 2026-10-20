// Same code shape as 0x0010b980 (propagated; names are from that function)
class RefObj_10f940 {
  public:
    virtual void AddRef();
    virtual void Release();
};

class ActionBase_10f940 {
  public:
    ActionBase_10f940();
    virtual void Update();
    char pad[0x18];
};

class SemaphoreWaitAction_10f940 : public ActionBase_10f940 {
  public:
    int mTarget;
    RefObj_10f940* mObj;
    SemaphoreWaitAction_10f940(int target, RefObj_10f940* obj);
    virtual void Execute();
};

SemaphoreWaitAction_10f940::SemaphoreWaitAction_10f940(int target, RefObj_10f940* obj) {
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
