// Same code shape as 0x0010b980 (propagated; names are from that function)
class RefObj_177550 {
  public:
    virtual void AddRef();
    virtual void Release();
};

class Action_177550 {
  public:
    Action_177550();
    virtual void Update();
    char pad[0x18];
};

class VisibilityAction_177550 : public Action_177550 {
  public:
    int mTarget;
    RefObj_177550* mObj;
    VisibilityAction_177550(int target, RefObj_177550* obj);
    virtual void Execute();
};

VisibilityAction_177550::VisibilityAction_177550(int target, RefObj_177550* obj) {
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
