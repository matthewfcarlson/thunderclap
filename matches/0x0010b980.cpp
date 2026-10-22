class RefObj_10b980 {
  public:
    virtual void AddRef();
    virtual void Release();
};

class Action_10b980 {
  public:
    Action_10b980();
    virtual void Update();
    char pad[0x18];
};

class FaceTargetAction : public Action_10b980 {
  public:
    int mTarget;
    RefObj_10b980* mObj;
    FaceTargetAction(int target, RefObj_10b980* obj);
    virtual void Execute();
};

FaceTargetAction::FaceTargetAction(int target, RefObj_10b980* obj) {
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
