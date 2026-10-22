// Same code shape as 0x0010b980 (propagated; names are from that function)
class RefObj_184750 {
  public:
    virtual void AddRef();
    virtual void Release();
};

class Action_184750 {
  public:
    Action_184750();
    virtual void Update();
    char pad[0x18];
};

class ShieldArcAction_184750 : public Action_184750 {
  public:
    int mTarget;
    RefObj_184750* mObj;
    ShieldArcAction_184750(int target, RefObj_184750* obj);
    virtual void Execute();
};

ShieldArcAction_184750::ShieldArcAction_184750(int target, RefObj_184750* obj) {
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
