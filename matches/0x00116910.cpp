// Same code shape as 0x0010b980 (propagated; names are from that function)
class RefObj_116910 {
  public:
    virtual void AddRef();
    virtual void Release();
};

class ActionBase_116910 {
  public:
    ActionBase_116910();
    virtual void Update();
    char pad[0x18];
};

class FaceTargetAction : public ActionBase_116910 {
  public:
    int mTarget;
    RefObj_116910* mObj;
    FaceTargetAction(int target, RefObj_116910* obj);
    virtual void Execute();
};

FaceTargetAction::FaceTargetAction(int target, RefObj_116910* obj) {
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
