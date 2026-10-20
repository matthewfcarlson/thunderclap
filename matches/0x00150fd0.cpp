// Same code shape as 0x0010b980 (propagated; names are from that function)
class RefObj_150fd0 {
  public:
    virtual void AddRef();
    virtual void Release();
};

class ActionBase_150fd0 {
  public:
    ActionBase_150fd0();
    virtual void Update();
    char pad[0x18];
};

class InterruptAccumulatorSetAction_150fd0 : public ActionBase_150fd0 {
  public:
    int mTarget;
    RefObj_150fd0* mObj;
    InterruptAccumulatorSetAction_150fd0(int target, RefObj_150fd0* obj);
    virtual void Execute();
};

InterruptAccumulatorSetAction_150fd0::InterruptAccumulatorSetAction_150fd0(int target, RefObj_150fd0* obj) {
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
