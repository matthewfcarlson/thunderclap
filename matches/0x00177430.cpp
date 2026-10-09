// Same code shape as 0x0010b980 (propagated; names are from that function)
class RefObj {
  public:
    virtual void AddRef();
    virtual void Release();
};

class ActionBase {
  public:
    ActionBase();
    virtual void Update();
    char pad[0x18];
};

class FaceTargetAction : public ActionBase {
  public:
    int mTarget;
    RefObj* mObj;
    FaceTargetAction(int target, RefObj* obj);
    virtual void Execute();
};

FaceTargetAction::FaceTargetAction(int target, RefObj* obj) {
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
