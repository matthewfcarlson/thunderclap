// Same code shape as 0x0010b980 (propagated; names are from that function)
class RefObj_10ba10 {
  public:
    virtual void AddRef();
    virtual void Release();
};

class Action_10ba10 {
  public:
    Action_10ba10();
    virtual void Update();
    char pad[0x18];
};

class FaceMotionAction_10ba10 : public Action_10ba10 {
  public:
    int mTarget;
    RefObj_10ba10* mObj;
    FaceMotionAction_10ba10(int target, RefObj_10ba10* obj);
    virtual void Execute();
};

FaceMotionAction_10ba10::FaceMotionAction_10ba10(int target, RefObj_10ba10* obj) {
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
