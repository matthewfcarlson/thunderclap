// Same code shape as 0x0010b980 (propagated; names are from that function)
class RefObj_175890 {
  public:
    virtual void AddRef();
    virtual void Release();
};

class ActionBase_175890 {
  public:
    ActionBase_175890();
    virtual void Update();
    char pad[0x18];
};

class FaceTargetAction : public ActionBase_175890 {
  public:
    int mTarget;
    RefObj_175890* mObj;
    FaceTargetAction(int target, RefObj_175890* obj);
    virtual void Execute();
};

FaceTargetAction::FaceTargetAction(int target, RefObj_175890* obj) {
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
