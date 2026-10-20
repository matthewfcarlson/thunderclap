// Same code shape as 0x0010b980 (propagated; names are from that function)
class RefObj_126780 {
  public:
    virtual void AddRef();
    virtual void Release();
};

class ActionBase_126780 {
  public:
    ActionBase_126780();
    virtual void Update();
    char pad[0x18];
};

class AcquireTargetAction_126780 : public ActionBase_126780 {
  public:
    int mTarget;
    RefObj_126780* mObj;
    AcquireTargetAction_126780(int target, RefObj_126780* obj);
    virtual void Execute();
};

AcquireTargetAction_126780::AcquireTargetAction_126780(int target, RefObj_126780* obj) {
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
