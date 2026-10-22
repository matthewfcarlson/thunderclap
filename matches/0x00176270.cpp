// Same code shape as 0x0010b980 (propagated; names are from that function)
class RefObj_176270 {
  public:
    virtual void AddRef();
    virtual void Release();
};

class Action_176270 {
  public:
    Action_176270();
    virtual void Update();
    char pad[0x18];
};

class TargetIconDistanceAction_176270 : public Action_176270 {
  public:
    int mTarget;
    RefObj_176270* mObj;
    TargetIconDistanceAction_176270(int target, RefObj_176270* obj);
    virtual void Execute();
};

TargetIconDistanceAction_176270::TargetIconDistanceAction_176270(int target, RefObj_176270* obj) {
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
