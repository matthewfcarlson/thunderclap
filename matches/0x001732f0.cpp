// Same code shape as 0x0010b980 (propagated; names are from that function)
class RefObj_1732f0 {
  public:
    virtual void AddRef();
    virtual void Release();
};

class ActionBase_1732f0 {
  public:
    ActionBase_1732f0();
    virtual void Update();
    char pad[0x18];
};

class LocomotionStateAction_1732f0 : public ActionBase_1732f0 {
  public:
    int mTarget;
    RefObj_1732f0* mObj;
    LocomotionStateAction_1732f0(int target, RefObj_1732f0* obj);
    virtual void Execute();
};

LocomotionStateAction_1732f0::LocomotionStateAction_1732f0(int target, RefObj_1732f0* obj) {
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
