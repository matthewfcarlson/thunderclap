// Same code shape as 0x0010b980 (propagated; names are from that function)
class RefObj_1301e0 {
  public:
    virtual void AddRef();
    virtual void Release();
};

class ActionBase_1301e0 {
  public:
    ActionBase_1301e0();
    virtual void Update();
    char pad[0x18];
};

class XPAction_1301e0 : public ActionBase_1301e0 {
  public:
    int mTarget;
    RefObj_1301e0* mObj;
    XPAction_1301e0(int target, RefObj_1301e0* obj);
    virtual void Execute();
};

XPAction_1301e0::XPAction_1301e0(int target, RefObj_1301e0* obj) {
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
