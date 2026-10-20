// Same code shape as 0x0010b980 (propagated; names are from that function)
class RefObj_12c080 {
  public:
    virtual void AddRef();
    virtual void Release();
};

class ActionBase_12c080 {
  public:
    ActionBase_12c080();
    virtual void Update();
    char pad[0x18];
};

class ThreatDodgeAction_12c080 : public ActionBase_12c080 {
  public:
    int mTarget;
    RefObj_12c080* mObj;
    ThreatDodgeAction_12c080(int target, RefObj_12c080* obj);
    virtual void Execute();
};

ThreatDodgeAction_12c080::ThreatDodgeAction_12c080(int target, RefObj_12c080* obj) {
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
