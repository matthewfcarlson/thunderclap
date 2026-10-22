// Same code shape as 0x0010b980 (propagated; names are from that function)
class RefObj_130150 {
  public:
    virtual void AddRef();
    virtual void Release();
};

class Action_130150 {
  public:
    Action_130150();
    virtual void Update();
    char pad[0x18];
};

class StatEndTrialAction_130150 : public Action_130150 {
  public:
    int mTarget;
    RefObj_130150* mObj;
    StatEndTrialAction_130150(int target, RefObj_130150* obj);
    virtual void Execute();
};

StatEndTrialAction_130150::StatEndTrialAction_130150(int target, RefObj_130150* obj) {
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
