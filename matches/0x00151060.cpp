// Same code shape as 0x0010b980 (propagated; names are from that function)
class RefObj_151060 {
  public:
    virtual void AddRef();
    virtual void Release();
};

class ActionBase_151060 {
  public:
    ActionBase_151060();
    virtual void Update();
    char pad[0x18];
};

class FaceTargetAction : public ActionBase_151060 {
  public:
    int mTarget;
    RefObj_151060* mObj;
    FaceTargetAction(int target, RefObj_151060* obj);
    virtual void Execute();
};

FaceTargetAction::FaceTargetAction(int target, RefObj_151060* obj) {
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
