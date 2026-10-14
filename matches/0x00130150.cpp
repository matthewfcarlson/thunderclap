// Same code shape as 0x0010b980 (propagated; names are from that function)
class RefObj_130150 {
  public:
    virtual void AddRef();
    virtual void Release();
};

class ActionBase_130150 {
  public:
    ActionBase_130150();
    virtual void Update();
    char pad[0x18];
};

class FaceTargetAction : public ActionBase_130150 {
  public:
    int mTarget;
    RefObj_130150* mObj;
    FaceTargetAction(int target, RefObj_130150* obj);
    virtual void Execute();
};

FaceTargetAction::FaceTargetAction(int target, RefObj_130150* obj) {
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
