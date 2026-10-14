// Same code shape as 0x0010b980 (propagated; names are from that function)
class RefObj_12ff10 {
  public:
    virtual void AddRef();
    virtual void Release();
};

class ActionBase_12ff10 {
  public:
    ActionBase_12ff10();
    virtual void Update();
    char pad[0x18];
};

class FaceTargetAction : public ActionBase_12ff10 {
  public:
    int mTarget;
    RefObj_12ff10* mObj;
    FaceTargetAction(int target, RefObj_12ff10* obj);
    virtual void Execute();
};

FaceTargetAction::FaceTargetAction(int target, RefObj_12ff10* obj) {
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
