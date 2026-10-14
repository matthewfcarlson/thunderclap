// Same code shape as 0x0010b980 (propagated; names are from that function)
class RefObj_10fa60 {
  public:
    virtual void AddRef();
    virtual void Release();
};

class ActionBase_10fa60 {
  public:
    ActionBase_10fa60();
    virtual void Update();
    char pad[0x18];
};

class FaceTargetAction : public ActionBase_10fa60 {
  public:
    int mTarget;
    RefObj_10fa60* mObj;
    FaceTargetAction(int target, RefObj_10fa60* obj);
    virtual void Execute();
};

FaceTargetAction::FaceTargetAction(int target, RefObj_10fa60* obj) {
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
