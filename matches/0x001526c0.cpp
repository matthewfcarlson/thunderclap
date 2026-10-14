// Same code shape as 0x0010b980 (propagated; names are from that function)
class RefObj_1526c0 {
  public:
    virtual void AddRef();
    virtual void Release();
};

class ActionBase_1526c0 {
  public:
    ActionBase_1526c0();
    virtual void Update();
    char pad[0x18];
};

class FaceTargetAction : public ActionBase_1526c0 {
  public:
    int mTarget;
    RefObj_1526c0* mObj;
    FaceTargetAction(int target, RefObj_1526c0* obj);
    virtual void Execute();
};

FaceTargetAction::FaceTargetAction(int target, RefObj_1526c0* obj) {
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
