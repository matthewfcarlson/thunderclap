// Same code shape as 0x0010b980 (propagated; names are from that function)
class RefObj_18d610 {
  public:
    virtual void AddRef();
    virtual void Release();
};

class ActionBase_18d610 {
  public:
    ActionBase_18d610();
    virtual void Update();
    char pad[0x18];
};

class TimerSetAction_18d610 : public ActionBase_18d610 {
  public:
    int mTarget;
    RefObj_18d610* mObj;
    TimerSetAction_18d610(int target, RefObj_18d610* obj);
    virtual void Execute();
};

TimerSetAction_18d610::TimerSetAction_18d610(int target, RefObj_18d610* obj) {
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
