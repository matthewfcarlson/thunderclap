// Same code shape as 0x0010b980 (propagated; names are from that function)
class RefObj_199630 {
  public:
    virtual void AddRef();
    virtual void Release();
};

class Action_199630 {
  public:
    Action_199630();
    virtual void Update();
    char pad[0x18];
};

class MissilePunchAction_199630 : public Action_199630 {
  public:
    int mTarget;
    RefObj_199630* mObj;
    MissilePunchAction_199630(int target, RefObj_199630* obj);
    virtual void Execute();
};

MissilePunchAction_199630::MissilePunchAction_199630(int target, RefObj_199630* obj) {
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
